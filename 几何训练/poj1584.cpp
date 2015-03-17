#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define eps 1e-8
#define pi acos(-1)
using namespace std;
struct point{
	double x,y;
	point (double x=0,double y=0):x(x),y(y){
	} 
};
point operator -(point a,point b){
	return point(b.x-a.x,b.y-a.y);
}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	if (x<0) return -1;
	return 1;
}
double across(point a,point b){
	return a.x*b.y-a.y*b.x;
}
double pd(point p0,point p1,point p2){
	return across(p1-p0,p2-p0);
}
double length(point a){
	return sqrt(a.x*a.x+a.y*a.y);
}
point o,p[10000];
int main(){
	int n,i;
	double r;
	while (~scanf("%d",&n) && n>=3){
		scanf("%lf%lf%lf",&r,&o.x,&o.y);
		for (i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		p[n].x=p[0].x;
		p[n].y=p[0].y;
		p[n+1].x=p[1].x;
		p[n+1].y=p[1].y;
		int t=0;//t=1
		for (i=2;i<=n+1;i++){
			if (dcmp(pd(p[i-2],p[i-1],p[i]))==1){
				t=1;
				break;
			}else if (dcmp(pd(p[i-2],p[i-1],p[i]))==-1){
				t=-1;
				break;
			}
		}
		int flag=0;
		if (t!=0){
			for (;i<=n+1;i++){
				if (dcmp(pd(p[i-2],p[i-1],p[i]))!=t && dcmp(pd(p[i-2],p[i-1],p[i]))!=0){
					flag=1;
					break;
				}
			}
		}
		if (flag || t==0)
			printf("HOLE IS ILL-FORMED\n");
		else{
			for (i=1;i<=n+1;i++){
				if (dcmp(pd(p[i-1],p[i],o))!=t && dcmp(pd(p[i-1],p[i],o))!=0){
					flag=1;
					break;
				}
			}
			if (!flag){
				for (i=0;i<n;i++){
					point v1=p[i+1]-p[i];
					point v2=o-p[i];
					double s=fabs(across(v1,v2)/length(v1));
					if (s<r){
						flag=1;
						break;
					}
				}
			}
			if(flag==1)  
                printf("PEG WILL NOT FIT\n");  
            else  
                printf("PEG WILL FIT\n");
		}
	}
	return 0;
}
