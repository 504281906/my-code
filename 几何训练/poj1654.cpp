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
using namespace std;
int d[10][2]={{0,0},{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
char s[1000010];
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while (T--){
		gets(s);
		double ans=0;
		double x=0,y=0;
		double xx,yy;
		x+=d[s[0]-'0'][0];
		y+=d[s[0]-'0'][1];
		if (s[0]!='5')
		for (int i=1;;i++){
			int p=s[i]-'0';
			if (p==5) break;
			xx=x+d[p][0];
			yy=y+d[p][1];
			ans+=(x*yy-xx*y);
			x=xx;
			y=yy; 
		}
		LL k=(LL)fabs(ans); 
		if (k&1) printf("%lld.5\n",k/2);
		else printf("%lld\n",k/2);
	}
	return 0;
}
