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
	int a[10];
	int n;
};
string ans[50000];
int vis[50000];
queue <node> q;
char c[3]={'A','B','C'};
int h[10]={0,1,2,6,24,120,720,5040};
void A(node &k){
	swap(k.a[0],k.a[7]);
	swap(k.a[1],k.a[6]);
	swap(k.a[2],k.a[5]);
	swap(k.a[3],k.a[4]);
}
void B(node &k){
	swap(k.a[3],k.a[2]);
	swap(k.a[2],k.a[1]);
	swap(k.a[1],k.a[0]);
	swap(k.a[4],k.a[5]);
	swap(k.a[5],k.a[6]);
	swap(k.a[6],k.a[7]);
}
void C(node &k){
	swap(k.a[1],k.a[2]);
	swap(k.a[1],k.a[6]);
	swap(k.a[6],k.a[5]);
}
int cantor(node k){
	int s=0,i,j;
	for (i=0;i<8;i++){
		int n=0;
		for (j=i+1;j<8;j++)
			if (k.a[i]>k.a[j]) n++;
		s+=n*h[7-i];
	}
	return s;
}
void Init(){
	memset(vis,0,sizeof(vis));
	//memset(ans,NULL,sizeof(ans));
	node k;
	int i;
	for (i=0;i<8;i++)
		k.a[i]=i;
	k.n=cantor(k);
	vis[k.n]=1;
	while (!q.empty()) q.pop();
	q.push(k);
	while (!q.empty()){
		k=q.front();
		q.pop();
		for (i=0;i<3;i++){
			node g=k;
			if (i==0) A(g);
			if (i==1) B(g);
			if (i==2) C(g); 
			g.n=cantor(g);
			if (!vis[g.n]){
				vis[g.n]=1;
				ans[g.n]=ans[k.n]+c[i];
				//cout<<ans[g.n]<<endl;
				q.push(g);
			}
		}
	}
}
string s1,s2;
int main(){
	Init();
	int hh[10],i;
	while (cin>>s1>>s2){
		for (i=0;i<8;i++)
			hh[s1[i]-'0']=i+1;
		node k;
		for (i=0;i<8;i++)
			k.a[i]=hh[s2[i]-'0'];
		cout<<ans[cantor(k)]<<endl;
	}
	return 0;
}
