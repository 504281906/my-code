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
point p[1010],pp[1010];
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double across(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
bool cmp(point a,point b){
	double k=across(a,b,p[0]);
	if (dcmp(k)<0) return false;
	else if (dcmp(k)==0 && (dcmp(dis(a,p[0])-dis(b,p[0]))==-1)) return false;
	return true;
}
int n,begin;
double l;
void gotu(){
	int k=0;
	for (int i=1;i<n;i++)
		if (p[k].y>p[i].y || (p[k].y==p[i].y && p[k].x>p[i].x))
			k=i;
	point t=p[k];
	p[k]=p[0];
	p[0]=t;
	sort(p+1,p+n,cmp);
	pp[0]=p[n-1];
	pp[1]=p[0];
	begin=1;
	int ll=1;
	while (ll<=n-1){
		double d=across(pp[begin-1],pp[begin],p[ll]);
		if (dcmp(d)>=0)
			pp[++begin]=p[ll++];
		else begin--;
	}
}
int main(){
	scanf("%d%lf",&n,&l);
	int i;
	for (i=0;i<n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	gotu();
	double s=2*pi*l+0.5;
	for (i=1;i<=begin;i++)
		s+=dis(pp[i-1],pp[i]);
	s+=dis(pp[0],pp[begin]);
	printf("%d\n",(int)s);
	return 0;
}
