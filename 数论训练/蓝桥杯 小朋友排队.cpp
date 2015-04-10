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
#define M 1000010
using namespace std;
int a[100010];
LL c[M+10],b[100010];
void add(int x){
	while(x<=M){
		c[x]++;
		x+=x&(-x);
	} 
}
int sum(int x){
	int ans=0;
	while (x>0){
		ans+=c[x];
		x-=x&(-x);
	}
	return ans;
}
int main(){
	int n;
	LL ans=0;
	int i;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]++;
		add(a[i]);
		b[i]=(i-sum(a[i]));
	}
	memset(c,0,sizeof(c));
	for (i=n;i>0;i--){
		add(a[i]);
		b[i]+=sum(a[i]-1);
		ans+=(1+b[i])*b[i]/2;
	}
	printf("%I64d\n",ans);
	return 0;
}
