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
int x[30],a[30][30];
int freex[30],freexnum;
int equ,var;
int solve(int t){
	int ans=0x3fffffff;
	int i,j;
	for (i=0;i<(1<<t);i++){
		int cnt=0;
		memset(x,0,sizeof(x));
		for (j=0;j<t;j++)
			if (i & (1<<j)){
				cnt++;
				x[freex[j]]=1;
			}else x[freex[j]]=0;
		int dx;
		for (j=var-t-1;j>=0;j--){
			for (dx=j;dx<var;dx++)
				if (a[j][dx]) break;
			x[dx]=a[j][var];
			for (int l=dx+1;l<var;l++)
				if (a[j][l])
					x[dx]^=x[l];
			cnt+=x[dx];
		}
		ans=min(ans,cnt); 
	} 
	for (i=0;i<(1<<t);i++){
		int cnt=0;
		memset(x,0,sizeof(x));
		for (j=0;j<t;j++)
			if (i & (1<<j)){
				cnt++;
				x[freex[j]]=1;
			}else x[freex[j]]=0;
		int dx;
		for (j=var-t-1;j>=0;j--){
			for (dx=j;dx<var;dx++)
				if (a[j][dx]) break;
			x[dx]=a[j][var+1];
			for (int l=dx+1;l<var;l++)
				if (a[j][l])
					x[dx]^=x[l];
			cnt+=x[dx];
		}
		ans=min(ans,cnt); 
	}
	return ans;
}
int Gauss(){
	int r,l,i,j;
	freexnum=0;
	for (r=0,l=0;r<equ && l<var;r++,l++){
		int mr=r;
		if (a[mr][l]==0)
			for (i=r+1;i<equ;i++)
				if (a[i][l]){
					mr=i;
					break;
				}
		if (a[mr][l]==0){
			r--;
			freex[freexnum++]=l;
			continue;
		}
		if (mr!=r)
			for (i=l;i<=var+1;i++)
				swap(a[mr][i],a[r][i]);
		for (i=r+1;i<equ;i++)
			if (a[i][l])
				for (j=l;j<=var+1;j++)
					a[i][j]^=a[r][j]; 
	}
	for (i=r+1;i<equ;i++)
		if (a[i][var]!=0 && a[i][var+1]!=0) return -1;
	return solve(var-r); 
}
int main(){
	equ=0;var=16;
	int i,j;
	for(i=0;i<4;i++){
		for (j=0;j<4;j++){
			char k;
			scanf("%c",&k);
			if (i>0) a[equ][(i-1)*4+j]=1;
			if (i<3) a[equ][(i+1)*4+j]=1;
			if (j>0) a[equ][i*4+j-1]=1;
			if (j<3) a[equ][i*4+j+1]=1;
			a[equ][i*4+j]=1;
			if (k=='b'){
				a[equ][var]=1;
				a[equ][var+1]=0;
			}
			else{
				a[equ][var]=0;
				a[equ][var+1]=1; 
			}
			equ++;
		}
		getchar();
	}
	int f=Gauss();
	if (f==-1) cout<<"Impossible"<<endl;
	else cout<<f<<endl;
	return 0;
}
