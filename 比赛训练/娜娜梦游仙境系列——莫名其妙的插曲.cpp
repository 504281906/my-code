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
int a[1100];
int main(){
	int T,n,i;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int M=0;
		for (i=0;i<n;i++){
			scanf("%d",&a[i]);
			if (M<a[i]) M=a[i];
		}
		sort(a,a+n);
		int k=a[1]-a[0];
		int f=1;
		for (i=2;i<n;i++)
			if (a[i]-a[i-1]!=k){
				f=0;break;
			}
		if (f){
			cout<<"Lose"<<endl;
			continue;
		}
		M-=n;
		if (M%2==0) cout<<"Lose"<<endl;
		else cout<<"Win"<<endl; 
	} 
	return 0;
}
