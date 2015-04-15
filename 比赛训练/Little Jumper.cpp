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
#define eps 1e-12
#define pi acos(-1)
#define INF 0x7fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;

double l,t1,b1,t2,b2,ds,df,g;
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
double go(double x,double y){
	return (x*x+y*y);
}
double cal(double x){
	double k=((ds+x)*ds-ds*ds)*g/2;
	double k1=(ds+x)*g/2;
	double f=(ds-ds*ds/(ds+x));
	double ans;
	if (dcmp(t1-f)>=0 && dcmp(f-b1)>=0)
		ans=(ds+x)*g;
	else{
		if (dcmp(f-t1)>=0) {
			double vx1=sqrt(k/t1);
			double vy1=k1/vx1;
			ans=go(vx1,vy1);
		}
		else{
			double vx2=sqrt(k/b1);
			double vy2=k1/vx2;
			ans=go(vx2,vy2);
		}
	} 
	double ans1;
	k=((df+l-x)*(l-x)-(l-x)*(l-x))*g/2;
	k1=(df+l-x)*g/2;
	f=(l-x)-(l-x)*(l-x)/(df+l-x);
	if (dcmp(t2-f)>=0 && dcmp(f-b2)>=0)
		ans1=(df+l-x)*g;
	else{
		if (dcmp(f-t2)>=0) {
			double vx1=sqrt(k/t2);
			double vy1=k1/vx1;
			ans1=go(vx1,vy1);
		}
		else{
			double vx2=sqrt(k/b2);
			double vy2=k1/vx2;
			ans1=go(vx2,vy2);
		}
	} 
	ans=max(ans,ans1);
	return ans;
}
int main(){
	freopen("jumper.in","r",stdin);
	freopen("jumper.out","w",stdout);
	while (~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&b1,&t1,&b2,&t2,&l,&ds,&df,&g)){
		double L,R,M,MM,Mv,MMv;
		L=0,R=l;
		while (L+eps<R){
			M=(R-L)/3+L;
			MM=(R-L)*2/3+L;
			Mv=cal(M);
			MMv=cal(MM);
			if (dcmp(Mv-MMv)<0) R=MM;
			else L=M;
		}
		printf("%.4f\n",sqrt(Mv));
	}
	return 0;
}
