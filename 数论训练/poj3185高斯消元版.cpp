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
int a[100][100],equ,var;
int x[30];
int freex[30];
int freexnum;
int solve(int t){ //枚举自由变元 
	int i,j,dx;
	int ans=0x3fffffff;
	for (i=0;i<(1<<t);i++){
		int cnt=0;
		memset(x,0,sizeof(x));
		for (j=0;j<t;j++)
			if (i & (1<<j)){
				x[freex[j]]=1;
				cnt++;
			}
			else x[freex[j]]=0;
		for (j=var-t-1;j>=0;j--){
			for (dx=j;dx<var;dx++)
				if (a[j][dx]) break;
			x[dx]=a[j][var];
			for (int l=dx+1;l<var;l++)
				if (a[j][l])
					x[dx]^=x[l];
			cnt+=x[dx];
		}
		ans=min(ans,cnt);
	}
	return ans;
}
int Gauss(){
	int l,r,i,j;
	freexnum=0;
	for (r=0,l=0;r<equ && l<var;r++,l++){
		int mr=r;
		if (a[mr][l]==0)
			for (i=r+1;i<equ;i++)
				if (a[i][l]){
					mr=i;
					break;
				}
		if (a[mr][l]==0){
			r--;
			freex[freexnum++]=l;
			continue;
		}
		if (mr!=r)
			for (i=l;i<=var;i++)
				swap(a[mr][i],a[r][i]);
		for(i=r+1;i<equ;i++)
			if (a[i][l])
				for (j=l;j<=var;j++)
					a[i][j]^=a[r][j];
	}
	memset(x,0,sizeof(x));
	int ans=0;
	for (i=l-1;i>=0;i--){
		int t=a[i][var];
		for (j=i+1;j<l;j++)
			t^=x[j]&a[i][j];
		x[i]=t;
		ans+=t;
	}
	return solve(var-r);
}
int main(){
	equ=0;var=20;
	for (int i=0;i<20;i++){
		int k;
		scanf("%d",&k); 
		if (i>0) a[equ][i-1]=1;
		if (i<19) a[equ][i+1]=1;
		a[equ][i]=1;
		a[equ++][var]=k;
	}
	cout<<Gauss()<<endl;; 
	return 0;
}
