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
string M[15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"}; 
string m,m1;
int day,day1,year,year1;
int pdy(int x){
	if (x % 400==0 || (x%4==0 && x % 100!=0))
		return 1;
	else return 0;
}
int main(){
	int T,i;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		char c;
		cin>>m>>day>>c>>year;
		cin>>m1>>day1>>c>>year1;
		int ans1=0;
		int ans2=0;
		ans1=ceil((year-2000)*1.0/4)-ceil((year-2000)*1.0/100)+ceil((year-2000)*1.0/400);
		ans2=ceil((year1-2000)*1.0/4)-ceil((year1-2000)*1.0/100)+ceil((year1-2000)*1.0/400);
		if (pdy(year)){
			for (i=0;i<12;i++)
				if (m==M[i]) break;
			if (i>1) ans1++;
		}
		if (pdy(year1)){
			for (i=0;i<12;i++)
				if (m1==M[i]) break;
			if (i>1 || (i==1 && day1>=29)) ans2++;
		}
		printf("Case #%d: %d\n",cas,ans2-ans1);
	}
	return 0;
}
