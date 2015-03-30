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
int n,i,a[10010];
int main(){
	while (~scanf("%d",&n)){
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		printf("%d\n",a[(n+1)/2]);
	}
	return 0;
}
