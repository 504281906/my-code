#include <iostream>
using namespace std;
int a[20][20];
int b[20][20];
void update(int x){
	int r=x/4;
	int l=x%4;
	b[r][l]^=1;
	if (r-1>=0) b[r-1][l]^=1;
	if (r+1<4) b[r+1][l]^=1;
	if (l-1>=0) b[r][l-1]^=1;
	if (l+1<4) b[r][l+1]^=1;
}
int go(){
	int i,j;
	for (i=0;i<4;i++)
		for (j=0;j<4;j++)
			if (b[i][j]!=b[0][0]) return 0;
	return 1;
}
int main(){
	int i,j;
	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			char k;
			scanf("%c",&k);
			if (k=='b') a[i][j]=0;
			else a[i][j]=1;
		}
		getchar();
	}
	int ans=20;
	for (i=0;i<(1<<16);i++){
		int t=0;
		for (int i1=0;i1<4;i1++)
			for (int i2=0;i2<4;i2++)
				b[i1][i2]=a[i1][i2];
		for (j=0;j<16;j++){
			if (i & (1<<j)){
				t++;
				update(j);
			}
		}
		if (ans>t && go()) {
			ans=t;
		}
	}
	if (ans==20) cout<<"Impossible"<<endl;
	else cout<<ans<<endl;
	return 0;
}
