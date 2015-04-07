#include<limits>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

#define LL long long
#define eps 1e-8
#define pi acos(-1)
#define INF 0x7fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;
int p,var,equ;
char s[100];
int x[100];
int a[100][100];
int k[100];
int ksm(int a,int b){
	int ans=1;int k=a;
	while (b){
		if (b & 1) ans=ans*k%p;
		k=k*k%p;
		b>>=1;
	}
	return ans;
}
int Gauss(){
	int r,l,i,j;
	for (r=0,l=0;r<equ,l<var;r++,l++){
		int mr=r;
		for (i=r+1;i<equ;i++)
			if (a[mr][l]<a[i][l])
				mr=i;
		if (a[mr][l]==0){
			//freex[freexnum++]=l;
			r--;
			continue;
		}
		if (mr!=r)
			for (j=l;j<=var;j++)
				swap(a[mr][j],a[r][j]);
		for (i=r+1;i<equ;i++)
			if (a[i][l]){
                for(j=l+1;j<=var;j++)
                    a[i][j] = ((a[i][j]*a[r][l]-a[r][j]*a[i][l])%p+p)%p;
                a[i][l]=0;
			}
	}
	for (i=r;i<equ;i++)
		if (a[i][l]!=0) return -1; //无解
	if (r<equ) return 0;
	else{
		for (i=var-1;i>=0;i--){
			int t=a[i][var];
			for (j=i+1;j<var;j++){
				if (a[i][j]) t-=a[i][j]*x[j];
				t=(t%p+p)%p; 
			}
			while (t%a[i][i]!=0) t+=p;
			x[i]=t/a[i][i]%p;
		}
		return 1;
	}
}
int main(){
	int T,i,j;
	scanf("%d",&T);
	while (T--){
		memset(x,0,sizeof(x));
		memset(a,0,sizeof(a));
		memset(k,0,sizeof(k));
		scanf("%d %s",&p,&s);
		int l=strlen(s);
		for (i=0;i<l;i++){
			if (s[i]=='*'){
				k[i]=0;
				continue;
			}
			else k[i]=s[i]-'a'+1;
		}
		for (i=0;i<l;i++){
			for (j=0;j<l;j++)
				a[i][j]=ksm(i+1,j); 
			a[i][l]=k[i];        
		}			
		var=equ=l;
		if (int f=Gauss()==1){
			for (i=0;i<var;i++)
				printf("%d ",x[i]);
			cout<<endl;
		}
		else cout<<f<<endl;
	}
	return 0;
}
