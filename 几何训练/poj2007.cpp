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
#define LL __int64
#define eps 1e-8
#define pi acos(-1)
using namespace std;
struct point{
	double x,y;
	point (double x=0,double y=0):x(x),y(y){}
};
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
double across(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
point p[100];
bool cmp(point a,point b){
	double k=across(a,b,p[0]);
	if (dcmp(k)<0) return false;
	else return true;
}
int main(){// 简单的几个点以原点为起点，作极角排序输出 
	scanf("%lf%lf",&p[0].x,&p[0].y);
	int n=1;
	while (~scanf("%lf%lf",&p[n].x,&p[n].y))
	{
		n++;
		//if (n==10) break;
	}
	sort(p+1,p+n,cmp);
	for (int i=0;i<n;i++)
		printf("(%.0f,%.0f)\n",p[i].x,p[i].y);
	return 0;
}
