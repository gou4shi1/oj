/************************************************************************
    > File Name:    zoj1004.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月24日 星期五 21时35分57秒
************************************************************************/

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int MAXN = 10000;

char src[MAXN],tar[MAXN];
int n;

stack<int> s;
bool ans[MAXN << 1];
int ans_l;

void dfs(int i,int j)
{
    if (j == n)
    {
        for (int k = 0; k != ans_l; ++k)
        {
            if (ans[k])
                printf("i");
            else
                printf("o");
            printf(" ");
        }
        printf("\n");
        return;
    }
    int last = -1;
    for (int k = n-1; k >= i; --k)
        if (src[k] == tar[j])
        {
            last = k;
            break;
        }
    if (last != -1)
    {
        int ori_top = -1;
        if (!s.empty())
            ori_top = s.top();
        while (i <= last)
        {
            s.push(i++);
            ans[ans_l++] = 1;
        }
        s.pop();
        ans[ans_l++] = 0;
        dfs(i,j+1);
        ans_l-=2;
        --i;
        while (!s.empty() && s.top() != ori_top)
        {
            if (src[s.top()] != tar[j])
            {
                s.pop();
                --ans_l;
                --i;
            }
            else
            {
                s.pop();
                ans[ans_l++] = 0;
                dfs(i,j+1);
                ans_l-=2;
                --i;
            }
        }
    }
    if (!s.empty() && src[s.top()] == tar[j])
    {
        int temp = s.top();
        s.pop();
        ans[ans_l++] = 0;
        dfs(i,j+1);
        s.push(temp);
        --ans_l;
    }
}

int main()
{
    while (scanf("%s%s",src,tar) == 2)
    {
        n = strlen(src);
        puts("[");
        s = stack<int>();
        ans_l = 0;
        dfs(0,0);
        puts("]");
    }
    return 0;
}
