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
int a[22],b[22];
int main(){
	int i;
	for (i=0;i<20;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	int ans=30;
	int cnt=1;
	a[0]^=1;a[1]^=1;
	for (i=1;i<20;i++)
		if (a[i-1]==1){
			cnt++;
			a[i]^=1;
			a[i+1]^=1;
		}
	ans=min(ans,cnt);
	cnt=0;
	for (i=1;i<20;i++)
		if (b[i-1]){
			cnt++;
			b[i]^=1;
			b[i+1]^=1;
		}
	ans=min(ans,cnt);
	cout<<ans<<endl;
	return 0;
}
