/************************************************************************
    > File Name:    zoj1259.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月24日 星期五 20时36分48秒
************************************************************************/

#include <cstdio>
#include <stack>

using namespace std;

const int MAXN = 10005;

int a[MAXN];

int main()
{
    bool temp(0);
    int n;
    while (scanf("%d",&n) == 1 && n)
    {
        if (temp)
            printf("\n");
        else
            temp = true;
        while (scanf("%d",&a[0]) == 1 && a[0])
        {
            for (int i = 1; i != n; ++i)
                scanf("%d",&a[i]);
            int front = 1;
            stack<int> s;
            s.push(front++);
            bool flag = true;
            for (int i = 0; i != n; ++i)
            {
                if (!s.empty() && s.top() == a[i])
                {
                    s.pop();
                    continue;
                }
                if (front == a[i])
                {
                    ++front;
                    continue;
                }
                if (front > a[i])
                {
                    flag = false;
                    break;
                }
                while (front < a[i])
                    s.push(front++);
                ++front;
            }
            puts(flag ? "Yes" : "No");
        }
    }
    return 0;
}
