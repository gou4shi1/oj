/************************************************************************
    > File Name:    zoj2812.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月26日 星期日 23时00分14秒
************************************************************************/

#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[256];
    while (scanf("%[^\n]%*c",str) == 1 && str[0] != '#')
    {
        int ans(0);
        for (int i = 0; i != strlen(str); ++i)
            if (str[i] != ' ')
                ans += (i+1) * (str[i]-'A'+1);
        printf("%d\n",ans);
    }
    return 0;
}
