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
#define eps 1e-8
#define pi acos(-1)
#define INF 0x7fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	return -1;
}
double a,b,c,x,y;
double cal(double x1){
	double y1=a*x1*x1+b*x1+c;
	double k=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
	return k;
}
int main(){
	scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&x,&y);
	double k=-b/a/2;
	double L,R,M,MM;
	if (dcmp(x-k)>=0){
		L=k;
		R=201;
	}else{
		L=-201;
		R=k;
	}
	double Mv,MMv;
	while (L+eps<R){
		M=(L+R)/2;
		MM=(M+R)/2;
		Mv=cal(M);
		MMv=cal(MM);
		if (dcmp(Mv-MMv)>=0) L=M;
		else R=MM;
	}
	printf("%.3f\n",Mv);
	return 0;
}
