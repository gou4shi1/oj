/************************************************************************
    > File Name:    UVa11988.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月03日 星期四 19时32分43秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100000 + 5;

char s[MAXN];
int n,last,cur,next[MAXN];

int main()
{
    while (scanf("%s",s+1) == 1)
    {
        n = strlen(s+1);
        last = cur = 0;
        next[0] = 0;
        for (int i=1; i <= n; i++)
        {
            char ch=s[i];
            if (ch == '[')
                cur = 0;
            else if (ch == ']')
                cur = last;
            else 
            {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last)
                    last = i;
                cur = i;
            }
        }
        for (int i = next[0]; i!= 0; i=next[i])
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
