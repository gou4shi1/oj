/************************************************************************
    > File Name:    UVa1339.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月16日 星期三 22时19分32秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200 + 10;

int main()
{
    char str1[MAXN],str2[MAXN];
    int alpha1[MAXN],alpha2[MAXN];

    while (scanf("%s%s",str1,str2) == 2)
    {
        int len = strlen(str1);
        memset(alpha1,0,sizeof(alpha1));
        memset(alpha2,0,sizeof(alpha2));
        for (int i = 0; i != len; ++i)
        {
            ++alpha1[str1[i]];
            ++alpha2[str2[i]];
        }
        sort(alpha1+'A',alpha1+'Z'+1);
        sort(alpha2+'A',alpha2+'Z'+1);
        if (equal(alpha1+'A',alpha1+'Z'+1,alpha2+'A'))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

