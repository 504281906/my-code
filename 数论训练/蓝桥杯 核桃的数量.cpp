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
	else return gcd(b,a%b);
}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans=a*b/gcd(a,b);
	ans=ans*c/gcd(ans,c);
	cout<<ans<<endl; 
	return 0;
}
