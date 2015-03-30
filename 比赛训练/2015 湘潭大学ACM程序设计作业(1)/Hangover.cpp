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
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
int main(){
	double a;
	while (~scanf("%lf",&a) && dcmp(a)!=0){
		double ans=0;
		int i;
		for (i=2;dcmp(a-ans)>0;++i){
			ans+=1*1.0/i;
		}
		printf("%d card(s)\n",i-2);
	}
	return 0;
}
