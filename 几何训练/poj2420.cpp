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
#define delta 0.98 //模拟退火递增变量 
#define INF 0x7fffffff 
using namespace std;
struct point{
	double x,y;
	point (double x=0,double y=0):x(x),y(y){
	}
};
int n;
point p[110];
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}
double sum(point a){
	double ans=0;
	for (int i=1;i<=n;i++)
		ans+=dis(a,p[i]);
	return ans;
}
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
double Search(point p[]){
	double ans=INF;
	int t=100; //初始温度
	point s=p[0];
	while (t>eps){
		int flag=1;
		while (flag){
			flag=0;
			for (int i=0;i<4;i++)
			{
				point z;
				z.x=s.x+d[i][0]*t;
				z.y=s.y+d[i][1]*t;
				double tmp=sum(z);
				if (tmp<ans){
					flag=1;
					s=z;
					ans=tmp;
				}
			}
		}
		t*=delta;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	printf("%.0f\n",Search(p));
	return 0;
}

