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
int gcd(int a,int b){
	if (b==0) return a;
	else gcd(b,a%b); 
}
int main(){
	int n,m;
	int t=1;
	while (~scanf("%d%d",&n,&m)){
		if (gcd(n,m)==1)
			printf("%10d%10d    Good Choice\n",n,m);
		else printf("%10d%10d    Bad Choice\n",n,m);
		cout<<endl;
	}
	return 0;
}
