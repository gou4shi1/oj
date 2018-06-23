/************************************************************************
    > File Name:    UVa1584.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月07日 星期一 19时41分21秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100 +5;

bool myless(const char* s,int p,int q)
{
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        if (s[(p + i) % n] != s[(q + i) % n])
            return s[(p + i) % n] < s[(q + i) % n];
    return false;
}

int main()
{
    int T;
    char s[MAXN];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int ans = 0;
        int n = strlen(s);
        for (int i = 1; i < n; ++i)
            if (myless(s,i,ans))
                ans = i;
        for (int i = 0; i < n; ++i)
            putchar(s[(ans + i) % n]);
        putchar('\n');
    }
    return 0;
}
