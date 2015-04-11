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
char s[1010];
int main(){
	int T,n;
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d%s",&n,&s);
		int l=strlen(s);
		int ans=0;
		int g=s[0]-'0';
		if (g<n)
		for (int i=1;i<l;i++){
			if (g>=i) g+=s[i]-'0';
			else{
				ans++;
				g+=s[i]-'0'+1;
			}
			if (g>=n) break;
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
