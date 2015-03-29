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
	int x,y;
	node(int x=0,int y=0):x(x),y(y){
	}
};
bool cmp(node a,node b){
	if (a.y==b.y)
		return a.x<b.x;
	return a.y<b.y;
}
char s[110][110];
node a[110];
int main(){
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for (i=0;i<m;i++){
		scanf("%s",&s[i]);
		a[i].x=i;
	}
	for (i=0;i<m;i++){
		int l=0;
		for (j=0;j<n;j++){
			for (k=j+1;k<n;k++)
				if (s[i][j]>s[i][k]) l++;
		}
		a[i].y=l;
	}
	sort(a,a+m,cmp);
	for (i=0;i<m;i++)
		printf("%s\n",s[a[i].x]);
	return 0;
}
