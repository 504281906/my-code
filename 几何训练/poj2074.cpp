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
struct hunt{
	point a,b;
	double lview,rview;
};
struct line{
	point a,b;
};
double getx(point a,point b,int y){
	return (y-b.y)/(b.y-a.y)*(b.x-a.x)+b.x;
}
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
bool cmp(hunt a,hunt b){
	return dcmp(a.lview-b.lview)<=0;
}
line hos,pro;
hunt k[10010];
int main(){
	double x1,x2,y;
	int n;
	while (~scanf("%lf%lf%lf",&x1,&x2,&y) && dcmp(x1+x2+y)){
		memset(k,0,sizeof(k));
		hos.a.x=x1;hos.b.x=x2;
		hos.a.y=hos.b.y=y;
		scanf("%lf%lf%lf\n%d",&x1,&x2,&y,&n);
		pro.a.x=x1;pro.b.x=x2;
		pro.a.y=pro.b.y=y;
		int t=0;
		for (int i=0;i<n;i++){
			scanf("%lf%lf%lf",&x1,&x2,&y);
			if (dcmp(y-hos.a.y)>=0 || dcmp(y-pro.a.y)<=0) continue;
			k[t].a.x=x1;k[t].b.x=x2;
			k[t].a.y=k[t].b.y=y;
			k[t].lview=getx(hos.b,k[t].a,pro.a.y);
			k[t].rview=getx(hos.a,k[t].b,pro.a.y);
			t++;
		}
		if (t==0||dcmp(k[0].lview-pro.b.x)>0){
			printf("%.2f\n",pro.b.x-pro.a.x);
			continue;
		}
		sort(k,k+t,cmp);
		double ans=0;
		if (dcmp(k[0].lview-pro.a.x)>0) ans=k[0].lview-pro.a.x;
		if (dcmp(k[0].rview-pro.a.x)<0) k[0].rview=pro.a.x;
		int m=t;
		t=0;
		double tmp;
		for (int i=1;i<m;i++){
			if (dcmp(k[t].rview-pro.b.x)>=0) break;
			tmp=k[i].lview-k[t].rview;
			if (dcmp(tmp)>0){
				t=i;
				if (dcmp(tmp-ans)>0) ans=tmp;
			}
			else if (dcmp(k[i].rview-k[t].rview)>0)
				t=i;
		}
		tmp=pro.b.x-k[t].rview;
		if (dcmp(tmp-ans)>0) ans=tmp;
		if (dcmp(ans)>0) printf("%.2f\n",ans);
		else cout<<"No View\n";
	}
	return 0;
}
