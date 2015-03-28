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
char A[200010],B[200010],C[200010];
double p[30][30];
int a[30],b[30],c[30];
int Gauss(int n,int m){
	int n1=0,m1=0;
	for (;n1<n && m1<m;n1++,m1++){
		int maxn=n1;
		for (int i=n1+1;i<n;i++)
			if(abs(p[i][m1])>abs(p[maxn][m1])) maxn=i;
		if (maxn!=n1)
			for (int i=m1;i<=m;i++)
				swap(p[n1][i],p[maxn][i]);
		if (p[n1][m1]==0){
			n1--;
			continue;
		}
		for (int i=n1+1;i<n;i++){
			if (p[i][m1]){
				LL ta=p[n1][m1];
				LL tb=p[i][m1];
				for (int j=m1;j<m+1;j++)
					p[i][j]=p[i][j]*ta-p[n1][j]*tb;		
			}
		} 
	}
	for (int i=n1;i<n;i++)
		if (p[i][m1]!=0) return -1;
	return 0;
}

int main(){
	while (~scanf("%s\n%s\n%s",&A,&B,&C)){
		//cout<<A<<B<<C<<endl;
		int n=strlen(A)/2;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(p,0,sizeof(p));
		for (int i=0;i<2*n;i++){
			a[A[i]-'A']++;
			b[B[i]-'A']++;
			c[C[i]-'A']++;
		}
		int ff=0;
		for (int i=0;i<26;i++)
			if (c[i]>a[i]+b[i]){
				puts("NO");
				ff=1;break;
			}
		if (ff) continue;
		LL ans=0;
		for (int i=0;i<26;i++){
			p[0][i]=a[i];
			p[1][i]=b[i]*a[i];
			ans+=c[i]*b[i];
		}
		p[0][26]=n;
		p[1][26]=ans-n;
		int f=Gauss(2,26);
		if (f==-1) puts("NO");
		else puts("YES"); 
	}
	return 0;
}
