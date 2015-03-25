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
#define delta 0.98 //ģ���˻��������
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
	scanf("%lf%d%d",&d,&n,&m); //Ŀ����d�㣬��n���ϰ������ֻ����m��
	for (i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);//�ϰ���λ�ú͸߶� 
	double ans=INF;
	for (i=0;i<=m;i++){	 //i���������� 
		double l=d/(i+1); //����һ�������ߵ������
		double vy=0;
		int f=0;
		for (j=0;j<n;j++){
			double x=a[j].x;
			double y=a[j].y;
			while (dcmp(x-l)>=0)
				x-=l;
			if (dcmp(x)==0){ //�ϰ��������ڷ������� 
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
