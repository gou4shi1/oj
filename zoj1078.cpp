/************************************************************************
    > File Name:    zoj1078.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月27日 星期一 00时09分27秒
************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 105;

char m[MAXN];
int len;

void convert(int n,int base)
{
    len = 0;
    do
    {
        m[len++] = n % base;
        n /= base;
    } while (n);
}

bool is_pali()
{
    for (int i = 0; i != len; ++i)
        if (m[i] != m[len-i-1])
            return false;
    return true;
}

int main()
{
    int n;
    while (scanf("%d",&n) == 1 && n)
    {
        printf("Number %d is ",n);
        bool flag(true);
        for (int i = 2; i <= 16; ++i)
        {
            convert(n,i);
            if (is_pali())
            {
                if (flag)
                {
                    printf("palindrom in basis");
                    flag = false;
                }
                printf(" %d",i);
            }
        }
        if (flag)
            printf("not a palindrom");
        printf("\n");
    }
    return 0;
}
