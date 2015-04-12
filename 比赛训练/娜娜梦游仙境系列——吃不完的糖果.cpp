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
int a[100010];
int p[100010];
int main(){
	int T,n,i;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		LL ans=0;
		LL k=0;
		int g=0;
		for (i=1;i<=n;i++){
			scanf("%d",&a[i]);
			k+=a[i];
			g+=a[i];
			p[i]=max(p[i-1],g);
			if (k<0) k=0;
			ans=max(ans,k);
		}
		k=0;
		for (i=n;i>=1;i--){
			k+=a[i];
			ans=max(k+p[i-1],ans);
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
