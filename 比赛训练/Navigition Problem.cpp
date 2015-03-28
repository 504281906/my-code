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
	point(double x=0,double y=0):x(x),y(y){
	}
};
point a,b;
double l;
int n;
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}
point find(point a,point b,double s){
	double k=dis(a,b)/s;
	point c;
	c.x=a.x+(b.x-a.x)/k;
	c.y=a.y+(b.y-a.y)/k;
	printf("%.2f,%.2f\n",c.x,c.y);
	return c;
}
int main(){
	int i;
	//freopen("out.txt","w",stdout);
	while (~scanf("%d%lf",&n,&l)){
		scanf("%lf%lf",&a.x,&a.y);
		double k=l;
		int f=0;
		for (i=1;i<=n;i++){
			scanf("%lf%lf",&b.x,&b.y);
			double h=dis(a,b);
			int t=1;
			while (dcmp(h-k)>=0){
				h-=k;
				a=find(a,b,k);
				f=1;
				k=l;
				t=0;
			}
			if (t) k=k-h;
			else k=l-h;
			a=b;
		}
		if (f==0) printf("No Such Points.\n"); 
	}
	return 0;
}
