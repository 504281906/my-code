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
	double x,y,v,l;
	point (double x=0,double y=0,double v=0,double l=0):x(x),y(y),v(v),l(l){
	} 
};
point g[100],p[100],pp[100];
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
double across(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(point a,point b){
	double k=across(a,b,g[0]);
	if (dcmp(k)<0) return false;
	if (dcmp(k)==0) return dis(a,p[0])<dis(b,p[0]);
	return true; 
}
int begin,n,m;
void gotu(){
	int k=0;
	for (int i=1;i<m;i++)
		if (g[k].y>g[i].y || (g[k].y==g[i].y && g[k].x>g[i].x))
			k=i;
	point gt=g[k];
	g[k]=g[0];
	g[0]=gt;
	sort(g+1,g+m,cmp);
	pp[0]=g[0];
	pp[1]=g[1];
	begin=1;
	int l=2;
	while (l<m){
		double d=across(pp[begin],g[l],pp[begin-1]);
		/*if (begin==1 || dcmp(d)>0)
			pp[++begin]=g[l++];
		else begin--;*/
		if (begin>1 && dcmp(d)<=0) begin--;
		else pp[++begin]=g[l++];
	}
}
int a[50];
int main(){
	int T=0;
	while (~scanf("%d",&n) && n){
		for (int i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&p[i].v,&p[i].l);
		int val=0x7fffffff;
		int vt=0;
		double ansl=0;
		int ans=0;
		for (int i=1;i<(1<<(n));i++){
			int tv=0;
			int t=0;
			double tl=0;
			m=0;
			memset(g,0,sizeof(g));
			memset(pp,0,sizeof(pp)); 
			for (int j=0;j<n;j++)
				if (i & (1<<j)){
					t++;
					tv+=p[j].v;
					tl+=p[j].l;
				}else g[m++]=p[j];
			if (tv>val || (tv==val && t>=vt)) continue;
			double s=0;
			if (m==1) s=0;else
			if (m==2) s=dis(g[0],g[1])*2;else{
			gotu();
			s=dis(pp[0],pp[begin]);
			for (int k=0;k<begin;k++)
				s+=dis(pp[k],pp[k+1]);
			}
			if (dcmp(tl-s)>=0){
				vt=t;
				val=tv;
				ansl=tl-s;
				int h=0;
				ans=i;
			}
		}
		if (T)cout<<endl;
		printf("Forest %d\nCut these trees:",++T);
		for (int i=0;i<n;i++)
			if (ans & (1<<i))
				printf(" %d",i+1);
		printf("\nExtra wood: %.2f\n",ansl);
	}
	return 0;
}
