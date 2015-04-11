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
int main(){
	int ans=0;
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13;
	for (i1=0;i1<5;i1++)
	for (i2=0;i2<5;i2++)
	for (i3=0;i3<5;i3++)
	for (i4=0;i4<5;i4++)
	for (i5=0;i5<5;i5++)
	for (i6=0;i6<5;i6++)
	for (i7=0;i7<5;i7++)
	for (i8=0;i8<5;i8++)
	for (i9=0;i9<5;i9++)
	for (i10=0;i10<5;i10++)
	for (i11=0;i11<5;i11++)
	for (i12=0;i12<5;i12++)
	for (i13=0;i13<5;i13++)
		if (i1+i2+i3+i4+i5+i6+i7+i8+i9+i10+i11+i12+i13==13)	ans++;
	cout<<ans<<endl;
	return 0;
}
