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
int a[50010];
int main(){
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=n;
	for (i=1;i<n;i++){
		int Max=a[i];
		int Min=a[i];
		for (j=i+1;j<=n;j++){
			if (a[j]>Max) Max=a[j];
			if (a[j]<Min) Min=a[j];
			if (Max-Min==j-i) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
