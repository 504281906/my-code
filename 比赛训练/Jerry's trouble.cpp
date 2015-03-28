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
#define P 1000000007
using namespace std;
int f[10000][1005];
LL ksm(int a,int b)
{
	LL s=1,k=a;
	while (b!=0)
	{
		if (b&1) s=s*k%P;
		k=k*k%P;
		b>>=1;
	}
	if (a<10000) f[a][b]=s%P;
	return s%P;
}
int main(){
	memset(f,0,sizeof(f));
	int n,m;
	while (~scanf("%d%d",&n,&m)){
		LL ans=0;
		for (int i=1;i<=n;i++){
			if (i<10000 && f[i][m]){
				ans=(ans+f[i][m])%P;
				continue;
			}
			else
				ans=(ans+ksm(i,m))%P; 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
