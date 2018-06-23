/************************************************************************
    > File Name:    UVa10340.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月13日 星期日 13时23分21秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000000;

char s[MAXN],t[MAXN];

int main()
{
    while (scanf("%s%s",s,t) == 2)
    {
        int j = 0,s_len = strlen(s),t_len = strlen(t);
        for (int i = 0; i != t_len; ++i)
            if (t[i] == s[j])
                ++j;
        if (j == s_len)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
