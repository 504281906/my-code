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
int main(){
	int n;
	scanf("%d",&n);
	for (int c=1;c<=n;c++){
		double x,y;
		scanf("%lf%lf",&x,&y);
		double r=x*x+y*y;
		double ans=r*pi/100;
		int k=ceil(ans);
		printf("Property %d: This property will begin eroding in year %d.\n",c,k);
	} 
	cout<<"END OF OUTPUT.\n";
	return 0;
}
