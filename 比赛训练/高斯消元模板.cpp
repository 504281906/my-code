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
int n,m;
int p[1010][1010];
bool freex[1010];
double x[1010];
void Debug(){
	int i,j;
	for (i=0;i<n;i++){
		for (j=0;j<=m;j++)
			printf("%5d",p[i][j]);
		cout<<endl;
	}
	return;
}
int Gauss(int n,int m){
	int n1=0,m1=0;
	for (;n1<n && m1<m;n1++,m1++){
		int maxn=n1;
		for (int i=n1+1;i<n;i++)
			if(abs(p[i][m1])>abs(p[maxn][m1])) maxn=i;
		if (maxn!=n1)
			for (int i=m1;i<=m;i++)
				swap(p[n1][i],p[maxn][i]);
		if (p[n1][m1]==0){
			n1--;
			continue;
		}
		for (int i=n1+1;i<n;i++){
			if (p[i][m1]){
				LL ta=p[n1][m1];
				LL tb=p[i][m1];
				for (int j=m1;j<m+1;j++)
					p[i][j]=p[i][j]*ta-p[n1][j]*tb;		
			}
		} 
	}
	memset(freex,0,sizeof(freex));
	int freex_t;
	//Debug();
	// 无解 
	for (int i=n1;i<n;i++)
		if (p[i][m1]!=0) return -1;
	// 无穷解 
	if(n1<m){
		for (int i=n1-1;i>=0;i--){
			int freex_num=0;
			for (int j=0;j<m;j++)
				if (p[i][j]!=0 && !freex[j]){
					freex_num++;
					freex_t=j;
				}
			if (freex_num>1) continue; //无法求出变元 
			int t=p[i][m];
			for (int j=0;j<m;j++)
				if (!p[i][j]!=0 && j!=freex_t) t-=p[i][j]*x[j];
			if (t!=0)
				x[freex_t]=t*1.0/p[i][freex_t];
			freex[freex_t]=1;   // 这个值是确定了 
		}
		return m-n1; //自由变元个数 
	}
	// 有唯一解
	for (int i=m-1;i>=0;i--){
		int t=p[i][m];
		for (int j=i+1;j<m;j++)
			if (p[i][j]!=0) t-=p[i][j]*x[j];
		if (t!=0) 
			x[i]=t*1.0/p[i][i];
	}
	return 0;
}

int main(){
	while (~scanf("%d%d",&n,&m)){
		for (int i=0;i<n;i++)
			for (int j=0;j<=m;j++)
				scanf("%d",&p[i][j]);
		memset(x,0,sizeof(x));
		int flag=Gauss(n,m);
		if (flag==-1) cout<<"无解！"<<endl;
		else if (flag==0){
			for (int i=0;i<m;i++)
				printf("x%d:%.0f\n",i+1,x[i]);
		}
		else{
			printf("有无穷解，自由变元个数为:%d\n",flag);
			for (int i=0;i<m;i++)
				if(!freex[i]) printf("x%d是不确定的\n",i+1);
				else
				printf("x%d:%.1f\n",i+1,x[i]);
		} 
	}
	return 0;
}
