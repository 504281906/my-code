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
vector<int> vt[100010];
int a[100010][5];
void dp(int u,int v){
	for (int i=0;i<vt[u].size();i++){
		int k=vt[u][i];
		if (k!=v){
			dp(k,u);
			a[u][1]+=a[k][0];
			a[u][0]+=max(a[k][0],a[k][1]);
		}
	}
	return;
}
int main(){
	int n,i;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++){
		vt[i].clear();
		scanf("%d",&a[i][1]);
	}
	for (i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	for (i=1;i<=n;i++)
		if (vt[i].size()==1){
			dp(i,-1);
			int ans=max(a[i][0],a[i][1]);
			cout<<ans<<endl;
			break;
		}
	return 0;
}
