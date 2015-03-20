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
int gcd(int a,int b){
	if (b==0) return a;
	else return gcd(b,a%b);
}
int main(){
	int T,i,n;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d",&n);
		int x=0,y=0,xx,yy;
		scanf("%d%d",&x,&y);
		int a=gcd(fabs(x),fabs(y));
		int b=0;
		double ans=0;
		for (i=1;i<n;i++){
			scanf("%d%d",&xx,&yy);
			a+=gcd(fabs(xx),fabs(yy));
			xx+=x;
			yy+=y;
			ans+=(x*yy)-(xx*y);
			x=xx;
			y=yy;
		}
		ans=fabs(ans)/2;
		b=(ans+1-a/2);
		printf("Scenario #%d:\n",cas);
		printf("%d %d %.1f\n",b,a,ans);
		if (cas!=T) cout<<endl;
	}
	return 0;
}
