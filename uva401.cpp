/************************************************************************
    > File Name:    UVa401.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月06日 星期日 21时15分04秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};

char r(char ch)
{
    if (isalpha(ch))
        return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main()
{
    char s[30];
    while (scanf("%s",s) == 1)
    {
        int len = strlen(s);
        bool p = true,m = true;
        for (int i = 0; i < (len+1)/2; i++)
        {
            if (s[i] != s[len-1-i])
                p = false;
            if (r(s[i]) != s[len-1-i])
                m = false;
        }
        printf("%s -- is %s.\n\n",s,msg[m*2+p]);
    }
    return 0;
}
