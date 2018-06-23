/************************************************************************
    > File Name:    zoj2483.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月25日 星期六 16时06分59秒
************************************************************************/

#include <cstdio>
#include <stack>

using namespace std;

const int MAXN = 1000;

int main()
{
    int prio[MAXN];
    prio['!'] = 3;
    prio['&'] = 2;
    prio['|'] = 1;
    int kase(0);
    char ch;
    while ((ch = getchar()) != EOF)
    {
        stack<char> s;
        char exp[MAXN];
        int len(0);
        do
        {
            if (ch == ' ')
               continue;
            if (ch == 'V'|| ch == 'F')
            {
                exp[len++] = ch;
                continue;
            }
            if (ch == '(')
            {
                s.push(ch);
                continue;
            }
            if (ch == ')')
            {
                while (s.top() != '(')
                {
                    exp[len++] = s.top();
                    s.pop();
                }
                s.pop();
                continue;
            }
            while (!s.empty() && prio[s.top()] > prio[ch])
            {
                exp[len++] = s.top();
                s.pop();
            }
            s.push(ch);
        } while ((ch = getchar()) != EOF && ch != '\n');
        while (!s.empty())
        {
            exp[len++] = s.top();
            s.pop();
        }
        stack<bool> ss;
        for (int i = 0; i != len; ++i)
        {
            if (exp[i] == 'V' || exp[i] == 'F')
            {
                ss.push(exp[i] == 'V');
                continue;
            }
            if (exp[i] == '!')
            {
                bool opr = ss.top();
                ss.pop();
                ss.push(!opr);
                continue;
            }
            bool opr1,opr2;
            opr1 = ss.top();
            ss.pop();
            opr2 = ss.top();
            ss.pop();
            if (exp[i] == '&')
                ss.push(opr1 && opr2);
            if (exp[i] == '|')
                ss.push(opr1 || opr2);
        }
        printf("Expression %d: %c\n",++kase,ss.top() ? 'V' : 'F');
    }
    return 0;
}
