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
#define delta 0.98 //ģ���˻��������
using namespace std;

int ans[10]={1,2,3,4,5,6,7,8,9,10};
int h[10]={1,1,2,6,24,120,720,5040,40320,362880};
int a[10],vis[10];
int main(){
	int n,i,j,t;
	printf("����һ������չ��������,����������Ƕ���\n");
	while(~scanf("%d",&n)){
		memset(vis,0,sizeof(vis));
		for (i=0;i<10;i++){
			t=n/h[9-i];
			n=n%h[9-i];
			int k=0;
			for (j=0;j<10;j++)
				if (!vis[j]){
					if (k==t){
						vis[j]=1;
						a[i]=ans[j];
						break;
					}
				 	k++;
				}
		}
		for (i=0;i<10;i++)
			printf("%d ",a[i]);
		cout<<endl; 
	} 
	return 0;
}
