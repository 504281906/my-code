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
int equ,var,a[100][100];
int Gauss(){
	int r,l,i,j;
	for(r=0,l=0;r<equ && l<var;r++,l++){
		int mr=r;
		if (a[mr][l]==0)
		for (i=r+1;i<equ;i++)
			if (a[i][l]){
				mr=i;
				break;
			}
		if (a[mr][l]==0){
			r--;
			continue;
		}
		if (mr!=r)
			for (i=0;i<=var;i++)
				swap(a[mr][i],a[r][i]);
		for (i=r+1;i<equ;i++)
			if (a[i][l])
				for (j=l;j<=var;j++)
					a[i][j]^=a[r][j];
	}
	for (i=r;i<equ;i++)
		if (a[i][l]!=0) return -1;
	return var-r; 
}
int main(){
	int T,i,j,n;
	scanf("%d",&T);
	while (T--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		equ=var=n;
		for (i=0;i<n;i++)
			scanf("%d",&a[i][n]);
		for (i=0;i<n;i++){
			int k;
			scanf("%d",&k);
			a[i][n]^=k;
			a[i][i]=1;
		}
		int v,u;
		while (~scanf("%d%d",&u,&v) && u+v)
			a[v-1][u-1]=1;
		int f=Gauss();
		if (f==-1) printf("Oh,it's impossible~!!\n");
		else{
			printf("%d\n",1<<f);
		}
	}
	return 0;
}
