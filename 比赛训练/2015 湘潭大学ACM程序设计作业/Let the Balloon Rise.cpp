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
string s,a[1011];
map<string,int>mp;
int main(){
	int n,i;
	while (~scanf("%d",&n)&&n){
		getchar();
		mp.clear();
		int t=0;
		for (i=0;i<n;i++){
			cin>>s;
			if (mp[s]==0) a[++t]=s;
			mp[s]++;
			//cout<<mp[s]<<endl;
		}
		string ans;
		int k=0;
		for (i=1;i<=t;i++)
			if (mp[a[i]]>k){
				ans=a[i];
				k=mp[a[i]];
			}
		cout<<ans<<endl;
	}
	return 0;
}
