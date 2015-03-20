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
using namespace std;
struct point{
	double x,y;
	point (double x=0,double y=0):x(x),y(y){
	}
};
point p[1010];
int dcmp(double x){
	if (fabs(x)<=eps) return 0;
	if (x>0) return 1;
	else return -1;
}
double across(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}
bool cmp(point a,point b){
	int  k=dcmp(across(a,b,p[0]));
	if (k==-1) return false;
	if (k==0) return dis(a,p[0])<dis(b,p[0]);
	return true;
}
int main(){
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int k=0;
		for  (int i=0;i<n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
			if (p[k].y>p[i].y || (p[k].y==p[i].y && p[k].x>p[i].y))
				k=i;
		}
		if (n<6){
			cout<<"NO"<<endl;
			continue;
		}
		point t=p[k];
		p[k]=p[0];
		p[0]=t;
		sort(p+1,p+n,cmp);
		int j;
		for (j=n-2;j>=0;j--)
			if (dcmp(across(p[0],p[n-1],p[j]))!=0) break;
		j++;
		for (int i=j;i<=(n-1+j)/2;i++){
			t=p[i];
			p[i]=p[n-1-i+j];
			p[n-1-i+j]=t;
		}
		p[n]=p[0];
		point a=p[0],b=p[1];
		int flag=0;
		int ans=1;
		int tt=0;
		for (int i=2;i<=n;i++){
			int k=dcmp(across(a,b,p[i]));
			if (k==0){
				flag=1;
			}else{
				tt++;
				if (!flag){
					ans=0;
					break;
				}
				else{
					a=p[i-1];
					b=p[i];
					flag=0;
				}
			}
		}
		if (ans && tt && flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
