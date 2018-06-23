/************************************************************************
    > File Name:	UVa514.cpp
    > Author:		gou4shi1
    > Mail:			gou4shi1@qq.com
    > Created Time: 2016年02月19日 星期五 00时09分01秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

const int MAXN = 1000+10;

int n,target[MAXN];

int main()
{
    while (scanf("%d",&n) == 1)
    {
        if (n == 0)
            break;
        while (scanf("%d",&target[1]) == 1)
        {
            if (target[1] == 0)
            {
                printf("\n");
                break;
            }
            for (int i = 2; i <= n; i++)
                scanf("%d",&target[i]);
            stack<int> s;
            int A = 1,B = 1;
            bool ok = true;
            while (B <= n)
            {
                if (A == target[B])
                {
                    ++A;
                    ++B;
                }
                else if (!s.empty() && s.top() == target[B])
                {
                    s.pop();
                    ++B;
                }
                else if (A <= n)
                    s.push(A++);
                else
                {
                    ok = false;
                    break;
                }
            }
            printf("%s\n",ok ? "Yes" : "No");
        }
    }
    return 0;
}
