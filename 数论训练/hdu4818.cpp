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
#define delta 0.98 //模拟退火递增变量
using namespace std;

double a[210][210];
double x[210];
int du[210];
int g[210][210];
int add[210];
int equ,var;
vector<int>v[210];

int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
} 
int Gauss(){
	int r,col,i,j;
	for (r=0,col=0;r<equ && col<var;r++,col++){
		int maxr=r;
		for (i=r+1;i<equ;i++)
			if (dcmp(fabs(a[i][col])-fabs(a[maxr][col]))>0) maxr=i;
		if (dcmp(a[maxr][col])==0) return 0;//无解，有自由变元 
		if (r!=maxr){
			for (i=col;i<var;i++)
				swap(a[maxr][i],a[r][i]);
			swap(x[r],x[maxr]);
		}
		x[r]/=a[r][col];
		for (i=col+1;i<var;i++)
			a[r][i]=a[r][i]/a[r][col];
		a[r][col] = 1;
		for (i=0;i<equ;i++)
		if (i!=r){
			x[i]=x[i]-x[r]*a[i][r];   //始终觉得这里有点问题 
			for (j=col+1;j<var;j++)
				a[i][j]-=a[r][j]*a[i][col];
			a[i][col]=0;
		}	
	}
	return 1;
}

int main(){
	int T,i,j,n,m;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);  // n表示有n个人，m代表m个关系 
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		memset(x,0,sizeof(x));
		for (i=0;i<n;i++){
			v[i].clear();
			du[i]=0;
		}
		for (i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u][v]=1;
		}
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (i!=j && g[i][j]){
					du[i]++;
					v[j].push_back(i); 
				}
		equ=var=n;
		for (i=0;i<n;i++){
			a[i][i]=-1;
			int sz=v[i].size();
			for (j=0;j<sz;j++){
				int k=v[i][j];
				if (i==k) continue;
				a[i][k]=1.0/du[k];
			}
		}
		for (i=0;i<n;i++)
			a[n-1][i]=1;
		x[n-1]=1;
		/*for (i=0;i<n;i++){
			for (j=0;j<n;j++)
				printf("%5.2f",a[i][j]);
			cout<<endl;
		}*/
		for (int k=0;k<n-1;k++)
			if (g[n-1][k]==0){
				for (i=0;i<n-1;i++)
					if (g[n-1][i]) a[i][var]=1.0/(du[n-1]+1);
					else a[i][var]=0;
				a[k][var]=1.0/(du[n-1]+1);
				a[n-1][var]=1;
				add[var]=k;
				var++;
			}
		if (!Gauss()){
			printf("INF\n");
			continue;
		}
		double now=x[n-1];
		int ans=-1;
		for (i=n;i<var;i++){
			if (dcmp(x[n-1]/a[n-1][i]-now)>0){
				ans=add[i];
				now=x[n-1]/a[n-1][i];
			}
		}
		printf("%d %d\n",1,ans);
	}
	return 0;
}
