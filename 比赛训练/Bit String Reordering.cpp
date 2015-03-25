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
int a[20],b[20],c[20],d[20];
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	int tt=0;
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (!a[i]) tt++;
		d[i]=a[i];
	}
	int t=1;
	int g=0,k;
	int t1=0;
	for (i=1;i<=m;i++){
		scanf("%d",&k);
		for (j=1;j<=k;j++){
			b[t]=g;
			c[t]=(g+1)%2;
			t++;
		}
		if (!g) t1+=k; 
		g=(g+1)%2;
	}
	int ans1=0,ans2=0;
	if (tt==t1)
	for (i=1;i<=n;i++){
		if (a[i]!=b[i]){
			for (j=i+1;j<=n;j++)
				if (a[j]==b[i]) break;
			ans1=ans1+(j-i);
			for (int k=j;k>i;k--)
				a[k]=a[k-1];
		}
	}
	else ans1=INF;
	if (tt==n-t1)
	for (i=1;i<=n;i++){
		if (d[i]!=c[i]){
			for (j=i+1;j<=n;j++)
				if (d[j]==c[i]) break;
			ans2=ans2+(j-i);
			for (int k=j;k>i;k--)
				d[k]=d[k-1];
		}
	}
	else ans2=INF;
	if (ans1<ans2) printf("%d\n",ans1);
	else printf("%d\n",ans2);
	return 0;
}
