//http://www.jb51.net/article/36020.htm 
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
int a;
char b;
#pragma pack(2) 
struct A{
	char d;
	char c;
	double a;
	int b;
	//char c;
	//char d;
};
struct B{
	char a;
	int b;
	char d;
	double c;
};
int main(){
	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;
	return 0;
}
