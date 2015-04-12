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
int a,b,c;
void go(){
	if (a>b){
		a=a+b;
		b=a-b;
		a=a-b;
	}
	if (a>c){
		a=a+c;
		c=a-c;
		a=a-c;
	}
	if (b>c){
		b=b+c;
		c=b-c;
		b=b-c;
	}
} 
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&a,&b,&c);
		go();
		if (b==a*5/4 &&a*5%4==0 && c==a*6/4 && a*6%4==0) cout<<"major"<<endl;
		else if (b==a*12/10 && a*12%10==0 && c==a*15/10 && a*15%10==0) cout<<"minor"<<endl;
		else cout<<"noise"<<endl;
	} 
	return 0;
}
