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
const int p=1000000007;
LL a[1010],b[1010];
int main(){
	int n,i;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	b[1]=1;
    for (i=2; i<=n; i++)
        b[i]=(b[i-1]*2%p);
    a[1]=1;
    a[2]=6;
    for (i=3; i<=n; i++)
        a[i]=(2*a[i-1]+b[i]+4*a[i-2])%p;
	LL ans=a[n]*4;
	for (i=2; i<n; i++)
        {
            ans+=((8*b[n-i]*a[i-1])%p+(8*a[n-i]*b[i-1])%p)%p;
            ans %= p;
        }
	if (n==1) ans=2;
	printf("%lld\n",ans);
	return 0;
}
