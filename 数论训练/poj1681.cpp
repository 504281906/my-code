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
int equ,var;
int a[500][500];
int x[500];
int Guass(){
	int l,r,i,j;
	for (r=0,l=0;r<equ&&l<var;r++,l++){
		int mr=r;
		if (a[mr][l]==0)
		for (i=r+1;i<equ;i++)
			if (a[i][l]){
				mr=i;
				break;
			}
		if (a[mr][l]==0){
			r--;
			continue;
		}
		if (mr!=r)
			for (i=0;i<=var;i++)
				swap(a[mr][i],a[r][i]);
		for (i=r+1;i<equ;i++)
			if (a[i][l])
				for (j=l;j<=var;j++)
					a[i][j]^=a[r][j];
	}
	for (i=r;i<equ;i++)
		if (a[i][l]!=0) return -1;
	memset(x,0,sizeof(x));
	int ans=0;
	for (i=l-1;i>=0;i--){
		int t=a[i][var];
		for (j=i+1;j<l;j++)
			t^=x[j]&a[i][j];
		x[i]=t;
		if (t) ans++;
	}
	return ans;
}
int main(){
	int T,n,i,j;
	scanf("%d",&T);
	while (T--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		equ=0;var=n*n;
		for (i=0;i<n;i++){
			getchar();
			for (j=0;j<n;j++){
				char k;
				scanf("%c",&k);
				a[equ][i*n+j]=1;
				if (i>0) a[equ][(i-1)*n+j]=1;
				if (j>0) a[equ][i*n+j-1]=1;
				if (i<n-1) a[equ][(i+1)*n+j]=1;
				if (j<n-1) a[equ][i*n+j+1]=1;
				if (k=='y') a[equ++][n*n]=0;
				else a[equ++][n*n]=1;
			}
		}
		int f=Guass();
		/*int t=0;
		for (i=0;i<n;i++){
			for (j=0;j<n;j++)
				printf("%d ",x[t++]);
			cout<<endl;
		}*/
		if (f==-1) cout<<"inf"<<endl;
		else 
		cout<<f<<endl;
	}
	return 0;
}
