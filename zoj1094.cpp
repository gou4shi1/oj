/************************************************************************
    > File Name:    zoj1094.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月24日 星期五 18时18分00秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int MAXN = 1024;

struct data{
    int row,col;
    data(int r = 0,int c = 0) : row(r),col(c) {}
};

int row[MAXN],col[MAXN];
char exp[MAXN];
int len;

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        char MATRIX[MAXN];
        int ROW,COL;
        scanf("%s%d%d",MATRIX,&ROW,&COL);
        row[MATRIX[0]] = ROW;
        col[MATRIX[0]] = COL;
    }
    row['('] = -2;
    col['('] = -2;
    row[')'] = -1;
    col[')'] = -1;
    while (scanf("%s",exp) == 1)
    {
        stack<data> s;
        int sum = 0;
        bool error = false;
        len = strlen(exp);
        for (int i = 0; i != len; ++i)
        {
            if (exp[i] != ')')
            {
                s.push(data(row[exp[i]],col[exp[i]]));
                continue; 
            }
            data temp = s.top();
            s.pop();
            while (!s.empty())
            {
                int tp_row = s.top().row;
                int tp_col = s.top().col; 
                s.pop();
                if (tp_row == -2)
                    break;
                if (tp_col != temp.row)
                {
                    error = true;
                    break;
                }
                sum += tp_row * temp.row * temp.col; 
                temp.row = tp_row;
            }
            if (error)
                break;
            s.push(temp);
        }
        if (error)
        {
            printf("error\n");
            continue;
        }
        data temp = s.top();
        s.pop();
        while (!s.empty())
        {
            int tp_row = s.top().row;
            int tp_col = s.top().col; 
            s.pop();
            if (tp_col != temp.row)
            {
                error = true;
                break;
            }
            sum += tp_row * temp.row * temp.col; 
            temp.row = tp_row;
        }
        printf("%d\n",sum);
    }
    return 0;
}
