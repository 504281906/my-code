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
#define INF 0x3fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;

int a[1010];
int l[150][150];
int f[1010][150];
int path[1010][150];
int main(){
	int n,i,j,k,m,s;
	freopen("quant.in","r",stdin);
	freopen("quant.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d%d",&m,&s);
	for (i=0;i<m;i++)
		for (j=0;j<s;j++){
			scanf("%d",&l[i][j]);
			f[i][j]=INF;
		}
	f[0][0]=0;
	for (i=1;i<=n;i++)
		for (j=0;j<s;j++){
			int Min=INF;
			for (k=0;k<s;k++){
				int t=f[i-1][k]+fabs(l[k&(m-1)][j]-a[i]);
				if (t<Min){
					Min=t;
					path[i][j]=k;
				}
			}
			f[i][j]=Min;
		}
	int ans=0;
	for (i=1;i<s;i++)
		if (f[n][i]<f[n][ans])
			ans=i;
	cout<<f[n][ans]<<endl;
	i=n;
	while(i>0){
		a[i]=ans;
		ans=path[i][ans];
		i--;
	}
	printf("%d",a[1]);
	for (i=2;i<=n;i++)
		printf(" %d",a[i]);
	cout<<endl;
	return 0;
}
