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
#define M 19999997
using namespace std;

struct matrix{
	LL a[2][2];
	matrix operator *(const matrix &g)const{
		matrix now;
		int k,i,j;
		for (i=0;i<2;i++)
			for (j=0;j<2;j++){
				now.a[i][j]=0;
				for (k=0;k<2;k++)
					now.a[i][j]=(now.a[i][j]+a[i][k]*g.a[k][j])%M;
			}
		return now;		
	}
	matrix pow(int n,const matrix &g){
		if (n==1) return g;
		matrix m=pow(n/2,g);
		if (n % 2)
			return m*m*g;
		else return m*m;
	}
};
int main(){
	int n;
	while (~scanf("%d",&n)){
		matrix s;
		s.a[0][0]=0,s.a[0][1]=s.a[1][0]=s.a[1][1]=1;
		s=s.pow(n,s);
		printf("%d\n",s.a[1][1]);
	}
	return 0;
}
