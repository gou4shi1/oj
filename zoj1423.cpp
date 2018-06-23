/************************************************************************
    > File Name:    zoj1423.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月25日 星期六 09时12分51秒
************************************************************************/

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int MAXN = 1000;

char str[MAXN];
int flag[MAXN];
int len;

stack<int> s;

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%*c%[^\n]",str);
        len = strlen(str);
        str[len] = '+';
        str[len+1] = '\0';
        memset(flag,false,sizeof(flag));
        s = stack<int>();
        for (int i = 0; i != len; ++i)
        {
            if (str[i] == ' ')
            {
                flag[i] = true;
                continue;
            }
            if (str[i] == '('|| str[i] == '+' || str[i] == '-')
            {
                s.push(i);
                continue;
            }
            if (str[i] == ')')
            {
                bool temp = false;
                while (!s.empty() && str[s.top()] != '(')
                {
                    temp = true;
                    s.pop();
                }
                int ori_top = s.top();
                s.pop();
                if (!temp || s.empty() || str[s.top()] == '(' || str[s.top()] == '+')
                {
                    flag[i] = flag[ori_top] = true;
                    if (temp)
                        s.push(len);
                }
            }
        }
        for (int i = 0; i != len; ++i)
            if (!flag[i])
                printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
