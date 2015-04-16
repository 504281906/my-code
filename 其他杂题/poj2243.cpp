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
int X1,X2,Y1,Y2;
int vis[10][10];
int d[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
struct point{
	int x,y,f,g,h,step;
	bool operator <(const point k)const{
		return f>k.f;
	}
};
int H(point k){
	return ((k.x-X2)+(k.y-Y2))*10;
}
int in(point g){
	if (g.x<0 || g.x>7 || g.y<0 || g.y>7) return 0;
	return 1;
}
priority_queue<point> q;
int ans=0;
void Astar(){
	point t,g;
	while (!q.empty()){
		t=q.top();
		q.pop();
		vis[t.x][t.y]=1;
		if (t.x==X2 && t.y==Y2){
			ans=t.step;
			return; 
		}
		for (int i=0;i<8;i++){
			g.x=t.x+d[i][0];
			g.y=t.y+d[i][1];
			if (in(g) && !vis[g.x][g.y]){
				g.g=t.g+23;
				g.h=H(g);
				g.f=g.g+g.h;
				g.step=t.step+1;
				q.push(g);
			}
		}
	}
}
int main(){
	char s[5];
	point k;
	while (gets(s)){
		ans=0;
		X1=s[0]-'a';Y1=s[1]-'1';
		X2=s[3]-'a';Y2=s[4]-'1';
		memset(vis,0,sizeof(vis));
		k.x=X1;
		k.y=Y1;
		k.g=k.step=0;
		k.h=H(k);
		k.f=k.g+k.h;
		while (!q.empty()) q.pop();
		q.push(k);
		Astar();
		printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],ans);
	}
	return 0;
}
