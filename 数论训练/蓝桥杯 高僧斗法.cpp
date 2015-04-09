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
int a[1010];
int main(){
	int k;
	char c;
	int t=0;
	while (1){
		scanf("%d%c",&k,&c);
		a[++t]=k;
		if (c=='\n') break;
	}
	k=0;
	int ans=0;
	while (2*k+2<=t){
		ans^=(a[2*k+2]-a[2*k+1]-1);
		k++;
	}
	if (ans==0) cout<<"-1"<<endl;
	else{
		for (int i=1;i<t;i++){
			for (int j=a[i]+1;j<a[i+1];j++){
				k=a[i];
				a[i]=j;
				int ans=0;
				for (int l=2;l<=t;l+=2)
					ans^=(a[l]-a[l-1]-1);
				if (ans==0){
					cout<<k<<" "<<j<<endl;
					break;
				}
				a[i]=k;
			}
		}
	}
	return 0;
}
