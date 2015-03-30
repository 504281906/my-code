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
string line,s;
int a[1010];
int main(){
	int i,n;
	while (~scanf("%d",&n) && n){
		int ans=0;
		int k=0;
		for (i=1;i<=n;i++){
			int g;
			scanf("%d",&g);
			if (g>k) ans+=(g-k)*6;
			else ans+=(k-g)*4;
			ans+=5;
			k=g;
		}
		printf("%d\n",ans);
	} 
	return 0;
}
