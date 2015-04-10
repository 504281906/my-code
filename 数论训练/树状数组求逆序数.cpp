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
int n,a[1010],c[1010];
void add(int x){
	while (x<=n){
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
	scanf("%d",&n);
	int ans=0;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		add(a[i]);
		ans+=(i+1-sum(a[i]));
	}
	cout<<ans<<endl;
	return 0;
}
