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

#define LL __int64
#define eps 1e-8
#define pi acos(-1)
#define INF 0x7fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;
int var,n;
int a[110][110];
int vis[110];
LL gg;
void Gauss(){
	int t=0;
	int r,col;
	LL ans=0; 
	for (col=var-1;col>=0;col--){
		int maxr=-1;
		for (int i=0;i<n;i++)
			if (a[i][col]==1 && !vis[i]){
				maxr=i;
				break;
			}
		if (maxr==-1 && a[n][col]==0) 
			ans+=gg;
		else if (maxr!=-1){
			vis[maxr]=1;
			ans+=gg;
			for (int i=0;i<=n;i++)
				if (a[i][col] && i!=maxr){
					for (int j=0;j<col;j++)
						a[i][j]^=a[maxr][j];
				}
		}
		gg>>=1;
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	int i,j;
	gg=1;var=0;
	LL k;
	for (i=0;i<n;i++){
		scanf("%lld",&k);
		j=0;
		while (k){
			if (k&1) a[i][j]=1;
			k>>=1;
			j++;
		}
		var=max(var,j);
	}
	for (i=0;i<var-1;i++){
		gg<<=1;
		a[n][i]=1;
	}
	memset(vis,0,sizeof(vis));
	a[n][var-1]=1;
	Gauss();
	return 0;
}
