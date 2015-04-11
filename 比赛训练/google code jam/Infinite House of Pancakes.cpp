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
int a[1010];
int main(){
	int T,i,n,j;
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d",&n);
		int Max;
		for (i=1;i<=n;i++){
			scanf("%d",&a[i]);
			Max=max(a[i],Max);
		}
		int ans=Max;
		for (i=1;i<=Max;i++){
			int s=i;
			for (j=1;j<=n;j++)
				if (a[j]>i){
					if (a[j]%i==0) s+=a[j]/i-1;
					else s+=a[j]/i;
				}
			ans=min(ans,s);
		}
		printf("Case #%d: %d\n",cas,ans);
	} 
	return 0;
}
