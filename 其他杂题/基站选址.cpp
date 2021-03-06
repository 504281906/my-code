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
#define delta 0.98 //ģ���˻��������
using namespace std;

struct point{
	LL x,y;
};
point u[1100],c[1100];
LL dis1(int X1,int Y1,int X2,int Y2){
	return (X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2);
}
LL dis2(int X1,int Y1,int X2,int Y2){
	return fabs(X1-X2)+fabs(Y1-Y2);
}
int A,B,n,m;
int k1,k2;
LL dis(int x,int y){
	LL ans=0;
	int i;
	for (i=1;i<=A;i++)
		ans+=dis1(u[i].x,u[i].y,x,y);
	LL t=INF;
	for (i=1;i<=B;i++)
		t=min(t,dis2(c[i].x,c[i].y,x,y));
	return ans+t;
}
LL go(int y){
	int M1,M2;
	int L=1,R=m;
	LL Mv1,Mv2;
	while (L<R){
		M1=ceil((R-L)*1.0/3)+L;
		M2=R-ceil((R-L)*1.0/3);
		Mv1=dis(M1,y);
		Mv2=dis(M2,y);
		if (Mv1>Mv2) L=M1;
		else R=M2;
	}
	k1=M1,k2=y;
	return Mv1;
}
int main(){
	int T,i;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d%d%d",&n,&m,&A,&B);
		for (i=1;i<=A;i++){
			scanf("%lld%lld",&u[i].x,&u[i].y);
		}
		for (i=1;i<=B;i++)
			scanf("%lld%lld",&c[i].x,&c[i].y);
		int L=1,R=n;
		int M1,M2;
		LL Mv1,Mv2;
		while (L<R){
			M1=ceil((R-L)*1.0/3)+L;
			M2=R-ceil((R-L)*1.0/3);
			Mv1=go(M1);
			Mv2=go(M2);
			if (Mv1>Mv2) L=M1;
			else R=M2;
		}
		printf("Case #%d: %lld\n",cas,Mv1);
	}
	return 0;
}
