#include <cstdio>  
#include <iostream>  
#include <cmath>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
#define maxn 100010  
typedef long long LL;  
LL m,n,p;  
LL Pow(LL a,LL b,LL mod)  
{  
    LL ans=1;  
    while(b)  
    {  
        if(b&1)  ans=(ans*a)%mod;  
        b>>=1;  
        a=(a*a)%mod;  
    }  
    return ans;  
}  
LL C(LL n,LL m)  
{  
    if(n<m)  
        return 0;  
    LL ans=1;  
    for(int i=1;i<=m;i++)  
    {  
        ans=ans*(((n-m+i)%p)*Pow(i,p-2,p)%p)%p;  
    }  
    return ans;  
}  
LL Lucas(LL n,LL m)  
{  
    if(m==0)  
        return 1;  
    return (Lucas(n/p,m/p)*C(n%p,m%p))%p;  
}
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%lld%lld%lld",&n,&m,&p);
        printf("%lld\n",Lucas(n,m));  
    }
    return 0;
}
//879467333 
