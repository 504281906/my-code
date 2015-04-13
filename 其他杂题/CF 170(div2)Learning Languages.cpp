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
int n,m,i,j,k;
int s[110][110],vis[110],a[110][110];
int main(){
	scanf("%d%d",&n,&m);
	int flag=1;
	memset(a,0,sizeof(a));
	for (i=1;i<=n;i++){
		scanf("%d",&k);
		if (k>0) flag=0;
		for (j=1;j<=k;j++){
			int d;
			scanf("%d",&d);
			a[i][d]=1;
		}
		s[i][i]=1;
	}
	for (k=1;k<=m;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if (a[i][k] && a[j][k])
					s[i][j]=1;
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if (s[i][k] && s[k][j])
					s[i][j]=1;
	int ans=0;
	memset(vis,0,sizeof(vis));
	for (i=1;i<=n;i++)
		if (!vis[i]){
			ans++;
			for (j=1;j<=n;j++)
				if(s[i][j])
					vis[j]=1; 
		}
	if (flag) printf("%d\n",n);
	else printf("%d\n",ans-1);
	return 0;
}
