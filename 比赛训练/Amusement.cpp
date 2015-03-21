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
#define INF 0x7fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;
char s[2010];
int b[2010];
int main(){
	freopen("china.in","r",stdin);
	freopen("china.out","w",stdout);
	int i;
	gets(s);
	int l=strlen(s);
	int a=0;
	int t=0;
	for (i=0;i<l-1;i++){
		a=a*10+(s[i]-'0');
		if (a>=2){
			b[t++]=a/2;
			a%=2;
		}
		else b[t++]=0;
	}
	a=a*10+(s[l-1]-'0');
	if (a & 1) b[t]=a/2;
	else {
		b[t]=a/2;
		if (b[t] %2==0) 
		{
			if (b[t]!=0) b[t]--;
			else 
			{
			b[t]=9;
				int k=t-1;
				while (b[k]-1<0){
					b[k]=9;
					k--;
				}
				b[k]--;
			}
		}
		else{
			if (b[t]!=1) b[t]-=2;
			else{
				b[t]=9;
				int k=t-1;
				while (b[k]-1<0){
					b[k]=9;
					k--;
				}
				b[k]--;
			}
		}
	}
	int j=0;
	while (b[j]==0) j++;
	for (i=j;i<=t;i++)
		printf("%d",b[i]);
	return 0;
}
