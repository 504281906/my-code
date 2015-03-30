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
int main(){
	int n,m,i;
	while (~scanf("%d%d",&n,&m)){
		int a=0,b=0;
		if (n>m){
			n=n+m;
			m=n-m;
			n=n-m;
		}
		for (i=1;;i++){
			if (a==0 && i*i>=n) a=i;
			if (i*i>m){
				b=i;
				break;
			}
		}
		//cout<<a<<" "<<b<<endl;
		if (a==b){
			cout<<m-n<<endl;
			continue;
		}
		int l,r,l1,r1;
		l=n-(a-1)*(a-1);
		r=a*a-n+1;
		l1=m-(b-1)*(b-1);
		r1=b*b-m+1;
		int ans=1;
		if ((a&1)!=(n&1)){
			l--;
			r--;
			ans++;
		}
		if (l<=l1 && r<=r1){
			ans+=(b-a-1)*2;
			if ((b & 1)==(m & 1)) ans++;
		}	
		else{
			if (l1<l) ans+=(b-a-1)*2+l-l1+1; 
			else ans+=(b-a-1)*2+r-r1+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
