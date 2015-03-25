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

int p[120];
int ans[1100];
int a[110][110];
int b[110];
void Init(){
    int vis[1010];
    memset(vis,0,sizeof(vis));
    memset(p,0,sizeof(p));
    int t=0;
    for (int i=2;;i++){
        if (!vis[i]) p[t++]=i;
        if (t==100) return;
        for (int j=0;j<t && (p[j]*i)<=1000;j++){
            vis[p[j]*i]=1;
            if (i%p[j]==0) break;
        }
    }
}
int gauss(int n,int m){
    int l,c,i,j,k;
    for (l=0,c=0;l<n&&c<m;c++){
        for (i=l;i<n;i++)
            if (a[i][c]) break;
        if (i<n){
            for (j=c;j<=m;j++)
                swap(a[l][j],a[i][j]);
            for (j=l+1;j<n;j++){
                if (a[j][c]){
                    for (k=c;k<=m;k++)
                        a[j][k]^=a[l][k];
                }
            }
            l++;
        }
    }
    return m-l;
}
void x2(){
    for (int i=1;i<=ans[0];i++)
        ans[i]*=2;
    for (int i=1;i<=ans[0];i++)
        if (ans[i]>9){
            ans[i+1]++;
            ans[i]-=10;
        }
    if (ans[ans[0]+1]!=0) ans[0]++;
}
void print(){
    ans[1]--;
    for (int i=ans[0];i>=1;i--)
        printf("%d",ans[i]);
    cout<<endl;
}
int main(){
    Init();
    int t,m,i,j;
    freopen("rsa.in","r",stdin);
    freopen("rsa.out","w",stdout);
    scanf("%d%d",&t,&m);
    //for (int i=1;i<=100;i++)
    //  cout<<p[i]<<endl;
    memset(a,0,sizeof(a));
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
        for(int j=0;j<t;j++){
            while(b[i]%p[j]==0){
                a[j][i]^=1;
                b[i]/=p[j];
            }
        }
    }
    int f=gauss(t,m);
    memset(ans,0,sizeof(ans));
    ans[0]=ans[1]=1;
    for (i=1;i<=f;i++)
        x2();
    print();
    return 0;
}
