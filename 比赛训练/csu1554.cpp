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
#include<queue>
#define LL long long
 
using namespace std;
int t;
priority_queue<int,vector<int>,greater<int> > qu;
int main(){
    while(scanf("%d",&t)!= EOF)
    {
        while(!qu.empty())
            qu.pop();
        LL l,r;
        l = r = 0 ; 
        int op,v;
        for(int i = 1; i<= t ;i ++)
        {
            scanf("%d",&op);
            if(op == 1)
            {    
                scanf("%d",&v);
                if(v <= r +1)
                {
                    r += v;
                    while(!qu.empty())
                    {
                        //printf("**\n");
                        int tmp = qu.top();
                        //printf("**%lld %d\n",r,tmp);
                        if(tmp <= r+1)
                        {
                           r += tmp;
                           qu.pop();
                        }else{
                          break;
                        }
                    }
                }else{
                    qu.push(v);
                }
            }else{
                printf("%lld\n",r+1);
            }
        }
    }
    return 0;
}
