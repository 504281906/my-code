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
point p[10010],g[10010];
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	return -1; 
}
double across(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(point a,point b){
	int k=dcmp(across(a,b,p[0]));
	if (k==-1) return false;
	if (k==0) return dis(a,p[0])<dis(b,p[0]);
	return true;
}
int n,begin;
void graham(){
	g[0]=p[0];
	g[1]=p[1];
	begin=1;
	int l=2;
	while (l<n){
		double d=across(g[begin-1],g[begin],p[l]);
		if (begin >=1 && dcmp(d)<=0) begin--;
		else g[++begin]=p[l++];
	}
}
int main(){
	scanf("%d",&n);
	int k=0,i;
	for (i=0;i<n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		if (p[k].y>p[i].y || (p[k].y==p[i].y && p[k].x>p[i].x))
			k=i;
	}
	point t=p[k];
	p[k]=p[0];
	p[0]=t;
	sort(p+1,p+n,cmp);
	graham();
	//for (i=0;i<=begin;i++)
	//	cout<<g[i].x<<" "<<g[i].y<<endl;
	double ans=0;
	for (i=2;i<=begin;i++)
		ans+=(fabs(across(g[i-1],g[i],g[0]))/2);
	printf("%d\n",(int)((int)ans/50));
	return 0;
}
