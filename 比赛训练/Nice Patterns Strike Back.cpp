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
int m,p,t;
char s[110];
int dp[100];
int n[150];
struct node{
	int a[40][40];
};
node d;
bool find(int x,int y){
	int i;
	for (i=0;i<m-1;i++){
		if ( (bool)(x&(1<<i))==(bool)(x&(1<<(i+1))) && (x & (1<<i))==(y & (1<<i)) && (x & (1<<(i+1)))==(y & (1<<(i+1))))
			return false;
	}
	return true;
}
void mul(node k1){
	int i,j;
	int k[50];
	for (i=0;i<(1<<m);i++){
		k[i]=dp[i];
		dp[i]=0;
	}
	for (i=0;i<(1<<m);i++){
		for (j=0;j<(1<<m);j++)
			dp[i]=(dp[i]+k[j]*k1.a[i][j])%p;
	}
	return;
}
node mul1(node k1,node k2){
	node pp;
	int i,j,k;
	memset(pp.a,0,sizeof(pp.a));
	for (i=0;i<(1<<m);i++){
		for (j=0;j<(1<<m);j++)
			for (k=0;k<(1<<m);k++)
				pp.a[i][j]=(pp.a[i][j]+k1.a[i][k]*k2.a[k][j])%p;
	}
	return pp;
}
void div2(){
	int i;
	int g=0;
	for (i=0;i<=t;i++){
		g=g*10+n[i];
		n[i]=g/2;
		g%=2; 
	}
	if (n[0]==0){
		for (i=1;i<=t;i++)
			n[i-1]=n[i];
		t--;
	}
}
void ksm(){
	while (t!=-1){
		if (n[t] & 1)
			mul(d);
		div2();
		d=mul1(d,d);
	}
	return;
}
int main(){
	int i,j;
	memset(d.a,0,sizeof(d.a));
	freopen("nice.in","r",stdin);
	freopen("nice.out","w",stdout);
	scanf("%s %d %d",&s,&m,&p);
	for (i=0;i<(1<<m);i++)
		for (j=0;j<(1<<m);j++)
			if (find(i,j)) d.a[i][j]=d.a[j][i]=1;
	int l=strlen(s);
	t=-1; 
	for (i=0;i<l;i++)
		n[++t]=s[i]-'0';
	if (n[t]==0){
		n[t]=9;
		int gg=t-1;
		while (n[gg]==0){
			n[gg]=9;
			gg--;
		}
		n[gg]--;
	}else n[t]--;
	if (n[0]==0){
		for (i=1;i<=t;i++)
			n[i-1]=n[i];
		t--;
	}
	for (i=0;i<(1<<m);i++)
		dp[i]=1;
	ksm();
	int ans=0;
	for (i=0;i<(1<<m);i++)
		ans=(ans+dp[i])%p;
	printf("%d\n",ans);
	return 0;
}
