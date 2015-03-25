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
#define INF 0x7fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;
struct point{
	double x,y;
};
point a[20];
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
int main(){
	double d;
	int n,m,i,j;
	scanf("%lf%d%d",&d,&n,&m); //目标在d点，有n个障碍，最多只能跳m次
	for (i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);//障碍的位置和高度 
	double ans=INF;
	for (i=0;i<=m;i++){	 //i代表反弹几次 
		double l=d/(i+1); //代表一个抛物线的最长距离
		double vy=0;
		int f=0;
		for (j=0;j<n;j++){
			double x=a[j].x;
			double y=a[j].y;
			while (dcmp(x-l)>=0)
				x-=l;
			if (dcmp(x)==0){ //障碍物正好在反弹点上 
				f=1;
				break;
			}
			double v1=l*sqrt(y/(2*x*(l-x)));
			if (dcmp(v1-vy)>=0) vy=v1;
		}
		if (f) continue;
		double vx=l/2.0/vy;
		double s;
		if (dcmp(vx-vy)>=0)
			vx=vy=sqrt(l/2.0);
			s=sqrt(vx*vx+vy*vy);
		if (dcmp(ans-s)>=0) ans=s;
	}
	printf("%.5f\n",ans);
	return 0;
}
