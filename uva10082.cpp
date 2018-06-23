/************************************************************************
    > File Name:    UVa10082.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月06日 星期日 19时44分10秒
************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    int i,c;
    while ((c = getchar()) != EOF)
    {
        for (i = 1; s[i] && s[i] != c; i++)
            ;
        if (s[i])
            putchar(s[i-1]);        
        else 
            putchar(c);
    }
    return 0;
}
