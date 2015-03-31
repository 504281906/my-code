// 基尔霍夫定理：电流流入的电流等于电流流出的电流. 
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
double a[110][110];
int equ,var;
double x[1100];
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	return -1;
}
void Gauss(){
	int r,l,i,j;
	for (r=0,l=0;r<equ && l<var;r++,l++){
		int mr=r;
		for (i=r+1;i<equ;i++)
			if (dcmp(fabs(a[mr][l])-fabs(a[i][l]))<0) mr=i;
		if (dcmp(a[mr][l])==0) return;
		if (mr!=r){
			for (i=l;i<var;i++)
				swap(a[mr][i],a[r][i]);
			swap(x[mr],x[r]);
		}
		x[r]/=a[r][l];
		for (i=l+1;i<var;i++)
			a[r][i]/=a[r][l];
		a[r][l]=1;
		for (i=0;i<equ;i++)
			if (i!=r){
				x[i]-=x[r]*a[i][l];
				for (j=l+1;j<var;j++)
					a[i][j]-=a[r][j]*a[i][l];
				a[i][l]=0;
			}
	}
}
int main(){
	int T,i,j,n,m;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d",&n,&m);
		equ=var=n;
		memset(a,0,sizeof(a));
		int u,v,w;
		for (i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			a[u-1][v-1]+=1.0/w;
			a[u-1][u-1]+=-1.0/w;
			a[v-1][u-1]+=1.0/w;
			a[v-1][v-1]+=-1.0/w;
		}
		for (i=0;i<n;i++)
			x[i]=0;
		x[0]=1;
		for (i=0;i<n;i++)
			a[n-1][i]=0;
		a[n-1][0]=1;
		Gauss();
		printf("Case #%d: %.2f\n",cas,x[n-1]);
	}
	return 0;
}
