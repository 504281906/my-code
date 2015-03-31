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
int equ,var,a[100][100],x[100];
void Gauss(){
	int r,l,i,j;
	for (r=0,l=0;r<equ && l<var;r++,l++){
		int mr=r;
		if (a[r][l]==0)
			for (i=r+1;i<equ;i++)
				if (a[i][l]){
					mr=i;
					break;
				}
		if (a[mr][l]==0) break;
		if (mr!=r)
		for (i=l;i<=var;i++)
			swap(a[mr][i],a[r][i]);
		for (i=r+1;i<equ;i++)
			if (a[i][l]){
				for(j=l;j<=var;j++)
					a[i][j]^=a[r][j]; 
			}
	}
	memset(x,0,sizeof(x));
	for (i=l-1;i>=0;i--){
		int t=a[i][var];
		for (j=i+1;j<l;j++)
			if (a[i][j]) t^=x[j]&a[i][j];
		x[i]=t;
	}
}
int main(){
	int T,i,j,k;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		memset(a,0,sizeof(a));
		equ=0;var=30;
		for (i=0;i<5;i++)
			for (j=0;j<6;j++){
				scanf("%d",&k);
				a[equ][i*6+j]=1;
				if (i>0) a[equ][(i-1)*6+j]=1;
				if (j>0) a[equ][i*6+j-1]=1;
				if (i<4) a[equ][(i+1)*6+j]=1;
				if (j<5) a[equ][i*6+j+1]=1;
				a[equ++][30]=k;
			}
		Gauss();
		int t=0;
		printf("PUZZLE #%d\n",cas);
		for (i=0;i<5;i++){
			for (j=0;j<6;j++)
				printf("%d ",x[t++]);
			cout<<endl;
		}
	}
	return 0;
}
