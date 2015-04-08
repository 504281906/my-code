#include <cstdio>  
#include <iostream>  
#include <cmath>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
#define maxn 100010  
typedef long long LL;
LL m,n,p;  
LL Pow(LL a,LL b,LL mod){
    LL ans=1;  
    while(b){  
        if(b&1)  ans=(ans*a)%mod;  
        b>>=1;  
        a=(a*a)%mod;
    }  
    return ans;
}
int main(){
    int t;  
    scanf("%d",&t);  
    p=10007;
    LL k;
	while(t--){
		scanf("%lld",&k);
		LL ans=(Pow(2,2*k-2,p)+Pow(2,k-1,p))%p;
		printf("%lld\n",ans);
    }
    return 0;
}
