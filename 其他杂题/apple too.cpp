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
int a;
int pd(int n,int m){
	LL ans=1;
	for (int i=1;i<=m;i++) {
		ans*=n;
		if (ans>=a) return 1;
	}
	return 0;
}
int DFS(int n,int m,int t){
	int f1,f2;
	int h1=pd(n+1,m);
	int h2=pd(n,m+1);
	if (h1 && h2)
		if (t==1) return 1;
		else return 0;
	if (h1)
		t==1?f1=1:f1=0;
	else f1=DFS(n+1,m,(t+1)%2);
	if (h2)
		t==1?f2=1:f2=0;
	else f2=DFS(n,m+1,(t+1)%2);
	if (t==0)
		if (f1+f2) return 1;
		else return 0;
	else 
		if (f1+f2==2) return 1;
		else return 0;
}
int main(){
	int n,m;
	while (~scanf("%d%d%d",&n,&m,&a)){
		if(n!=1)
		if (!DFS(n,m,0)) cout<<"lose"<<endl;
			else cout<<"win"<<endl;
		else{
			int t=0,flag=1;
			while (!pd(2,m) && !pd(1,m+1)){
				if (DFS(2,m,0)==0){
					if (t==0) cout<<"win"<<endl;
					else cout<<"lose"<<endl;
					flag=0;
					break;
				}else m++;
				t=(t+1)%2;
			}
			if (flag) cout<<"draw"<<endl;
		}
	}
	return 0;
}
