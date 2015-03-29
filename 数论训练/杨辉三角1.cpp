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
LL a[1010][1010]; 
int main(){
	a[1][1]=a[2][1]=a[2][2]=1;
	int i,j;
	for (i=3;i<=1001;i++)
		for (j=1;j<=i;j++)
			if (j==1 || j==i) a[i][j]=1;
			else  a[i][j]=a[i-1][j-1]+a[i-1][j];
	while (~scanf("%d%d",&i,&j)){
		printf("%lld\n",a[i][j]);
	}
	return 0;
}
