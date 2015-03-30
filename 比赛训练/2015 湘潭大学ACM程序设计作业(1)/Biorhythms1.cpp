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
	int a=23,b=28,c=33,i,x,y,z,d;
	int a1,b1,c1;
	for (i=1;;i++)
		if (c*b*i%a==1){
			a1=c*b*i;
			break;
		}
	for (i=1;;i++)
		if(a*c*i%b==1){
			b1=a*c*i;
			break;
		}
	for (i=1;;i++)
		if(a*b*i%c==1){
			c1=a*b*i;
			break;
		}
	int cas=1;
	int k=a*b*c;
	while (~scanf("%d%d%d%d",&x,&y,&z,&d) && (x+y+z+d)!=-4){
		int ans=(a1*x+b1*y+c1*z-d+k)%k;
		if (ans==0) ans=k;
		printf("Case %d: the next triple peak occurs in %d days.\n",cas++,ans);
	}
	return 0;
}

