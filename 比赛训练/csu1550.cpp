#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <cstdlib>
using namespace std;
const int maxn = 210000;
char str[maxn];
int one[28], two[28], three[28], three2[28];
int main()
{
//    freopen("D.txt","r",stdin);
    int n, len;
    while(scanf("%s", str)!=EOF)
    {
        len = strlen(str);
        n = len/2;
        memset(one, 0, sizeof(one));
        memset(two, 0, sizeof(two));
        memset(three, 0, sizeof(three));
        for(int i = 0; i < len; i++)
            one[str[i]-'A']++;
        scanf("%s", str);
        for(int i = 0; i < len; i++)
            two[str[i]-'A']++;
        scanf("%s", str);
        for(int i = 0; i < len; i++)
            three[str[i]-'A']++;
        for(int i = 0; i < 28; i++)
            three2[i] = three[i];
        bool flag = true;
        for(int i = 0; i < 3; i++)
            if(one[i] + two[i] < three[i])
                flag = false;
        if(flag)
        {
            int cnt = 0;
            int cnt2 = 0;
            for(int i = 0; i < 28; i++)
            {
                cnt += min(one[i], three[i]);
                cnt2 += min(two[i], three[i]);
            }
            if(cnt >= n && cnt2 >= n)
                ;
            else
                flag = false;
        }
        else
            flag = false;
        if(flag)
        {
            for(int i = 0; i < 28; i++)
                three[i] -= min(three[i], one[i]);
            for(int i = 0; i < 28; i++)
                if(three[i] > two[i])
                    flag = false;
            if(flag)
            {
                for(int i = 0; i < 28; i++)
                    three2[i] -= min(three2[i], one[i]);
                for(int i = 0; i < 28; i++)
                    if(three2[i] > two[i])
                        flag = false;
                if(flag)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
                printf("NO\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
