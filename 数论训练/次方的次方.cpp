// 求pow(a,pow(b,c)) % p  
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
int a[100010];
void oula(){
	memset(a,0,sizeof(a));
	a[1]=1;
	for (int i=2;i<=100000;i++)
		if (!a[i]){
			for (int j=i;j<100000;j++){
				if (!a[j])
					a[j]=j;
				a[j]=a[j]*i/(i-1);
			}
		}
}
int ksm(int a,int b,int p){
	int ans=1,k=a;
	while (b){
		if (b&1) ans=ans*k%p;
		k=k*k%p;
		b>>=1;
	}
	return ans;
}
int main(){
	oula();
	int d,b,c,p;
	while (~scanf("%d%d%d%d",&d,&b,&c,&p)){
		int k=a[p];
		int ans=ksm(d,ksm(b,c,k),p);
		cout<<ans<<endl;
	}
	return 0;
}
