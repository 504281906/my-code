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
LL f[20];
int main(){
	int n,m,i;
	scanf("%d%d",&n,&m);
	int k=n-1;
	f[1]=n-1-m;
	while(i<=(n+1)){
		double g=(f[i-1]*n+m)*1.0/(n-1);
		//g=g*(n-1)-m;
		if (floor(g)==g){
			f[i]=g;
			i++;
		}
		else{
			f[1]+=k;
			i=2;
		}
	}
	printf("ԭ��Ҭ�����ٵĸ�����%lld\n",f[n+1]*n+m);
	k=1;
	for (i=n+1;i>=1;i--){
		printf("��%d�������ٵ�Ҭ�Ӹ�����:%lld=%lld*%d+%d,�ص�%lld��\n",k++,f[i]*n+m,f[i],n,m);
	}
	return 0;
}
