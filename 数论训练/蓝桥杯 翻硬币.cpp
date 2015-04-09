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
char a[1100],b[1100];
int main(){
	gets(a);
	gets(b);
	//cout<<a<<endl<<b<<endl; 
	int l=strlen(a);
	int ans=0,i;
	for (i=0;i<l;i++)
		if (a[i]!=b[i]){
			if (a[i+1]=='*') a[i+1]='o';
			else a[i+1]='*';
			ans++;
		}
	cout<<ans<<endl;
	return 0;
}
