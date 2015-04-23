#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
int a[1000][1000],b[1000][1000],c[1000],n,m,i,j,k;
int main(){
	int mx;
	int a1,b1,c1;
	while (~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				b[i][j]=b[i-1][j]+a[i][j];
			}
		mx=0;
		for (i=1;i<=n;i++){
			for (j=1;j<=n-i+1;j++){   // b[i+j-1][k]-b[j-1][k]==这一字段的序列
				memset(c,0,sizeof(c));
				for (k=1;k<=m;k++){
					c[k]=max(c[k-1]+b[i+j-1][k]-b[j-1][k],b[i+j-1][k]-b[j-1][k]);
					c[k]=max(0,c[k]);
					//mx=max(mx,c[k]);
					if (mx<c[k]){
						mx=c[k];
						a1=j;
						b1=i+j-1;
						c1=k;
					}
				}
			}
		}
		cout<<mx<<endl;
		cout<<a1<<" "<<b1<<" "<<c1<<endl;
	}
	return 0;
}