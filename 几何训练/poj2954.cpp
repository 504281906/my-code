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
struct point{
	int x,y;
};
point p[10];
int gcd(int a,int b){
	if (b==0) return a;
	else return gcd(b,a%b);
}
int across(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
int main(){
	while (~scanf("%d%d%d%d%d%d",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y)){
		if (p[0].x==0 && p[0].y==0 && p[1].x==0 && p[1].y==0 && p[2].x==0 && p[2].y==0)
	    	break;
		int area=fabs(across(p[0],p[1],p[2]))/2;
		int s=gcd(fabs(p[0].x-p[1].x),fabs(p[0].y-p[1].y));
		s+=gcd(fabs(p[1].x-p[2].x),fabs(p[1].y-p[2].y));
		s+=gcd(fabs(p[0].x-p[2].x),fabs(p[0].y-p[2].y));
		int ans=area+1-s/2;
		printf("%d\n",ans);
	}
	return 0;
}
