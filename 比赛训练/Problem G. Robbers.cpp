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
struct node{
	int id;
	double x;
};
int cmp(node a,node b){
	return a.x-b.x>eps;
}
node f[1010];
int a[1010],b[1010];
int n,m,y,i;
int main(){
	freopen("robbers.in","r",stdin);
	freopen("robbers.out","w",stdout);
	scanf("%d%d%d",&n,&m,&y);
	int m1=m;	
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
		f[i].id=i;
		b[i]=(int)(m*a[i]*1.0/y);
		f[i].x=(m*a[i]*1.0/y)-(int)(m*a[i]*1.0/y);
		m1-=b[i];
	}
	sort(f,f+n,cmp);
	for (i=0;i<n;i++){
		if (m1==0) break;
		b[f[i].id]++;
		m1--;
	}
	printf("%d",b[0]);
	for (i=1;i<n;i++)
		printf(" %d",b[i]);
	cout<<endl;
	return 0;
}
