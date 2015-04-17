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

struct point{
	LL x,y;
};
point u[1100],c[1100];
LL dis2(int X1,int Y1,int X2,int Y2){
	return fabs(X1-X2)+fabs(Y1-Y2);
}
int A,B,n,m;
int k1,k2;
LL sx,sy,xt,yt; 
LL dis(int x,int y,int t){
	LL ans=0;
	ans+=xt+yt+A*x*x+A*y*y-2*x*sx-2*y*sy;
	ans+=dis2(c[t].x,c[t].y,x,y);
	return ans;
}
LL go(int y,int t){
	int M1,M2;
	int L=1,R=m;
	LL Mv1,Mv2;
	while (L<R){
		M1=ceil((R-L)*1.0/3)+L;
		M2=R-ceil((R-L)*1.0/3);
		Mv1=dis(M1,y,t);
		Mv2=dis(M2,y,t);
		if (Mv1>Mv2) L=M1;
		else R=M2;
	}
	return Mv1;
}
int main(){
	int T,i;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d%d%d",&n,&m,&A,&B);
		sx=0,sy=0,xt=0,yt=0;
		for (i=1;i<=A;i++){
			scanf("%lld%lld",&u[i].x,&u[i].y);
			sx+=u[i].x;
			sy+=u[i].y;
			xt+=u[i].x*u[i].x;
			yt+=u[i].y*u[i].y;
		}
		LL sum=INF;
		for (i=1;i<=B;i++){
			scanf("%lld%lld",&c[i].x,&c[i].y);
			int L=1,R=n;
			int M1,M2;
			LL Mv1,Mv2;
			while (L<R){
				M1=ceil((R-L)*1.0/3)+L;
				M2=R-ceil((R-L)*1.0/3);
				Mv1=go(M1,i);
				Mv2=go(M2,i);
				if (Mv1>Mv2) L=M1;
				else R=M2;
			}
			sum=min(sum,Mv1);
		}
		printf("Case #%d: %lld\n",cas,sum);
	}
	return 0;
}
