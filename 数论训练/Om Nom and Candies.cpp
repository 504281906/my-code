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
#define eps 1e-10
#define pi acos(-1)
#define INF 0x7fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	return -1;
}
int main(){
	LL c,hr,hb,wr,wb;
	scanf("%I64d%I64d%I64d%I64d%I64d",&c,&hr,&hb,&wr,&wb);
	if (dcmp(hb*1.0/wb-hr*1.0/wr)<0){ //保证蓝色是最大的 
		swap(hr,hb);
		swap(wr,wb);
	}
	LL l=c;
	LL k=l/wb;
	LL ans=k*hb;
	l=c-k*wb;
	if (l>=wr){
		ans+=(l/wr)*hr;
		l-=l/wr*wr;
	}
	if (hr<=hb && wr>=wb)
		cout<<ans<<endl;
	else{
		LL gg=ans;
		while (k>0 && l){
			k--;
			l+=wb;
			gg-=hb;
			if (l>=wr){
				gg+=l/wr*hr;
				l-=l/wr*wr;
			}
			if (gg>ans) ans=gg;
		}
		cout<<ans<<endl;
	}
	return 0;
}
