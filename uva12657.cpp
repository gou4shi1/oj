/************************************************************************
    > File Name:    UVa12657.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月03日 星期四 20时25分11秒
************************************************************************/

#include <cstdio>

using namespace std;

const int MAXN = 100000 + 5;

int left[MAXN],right[MAXN];

void link(int L,int R)
{
    right[L] = R;
    left[R] = L;
}

int main()
{
    int n,m,kase = 0;
    while (scanf("%d%d",&n,&m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            left[i] = i-1;
            right[i] = i+1;
        }
        right[n] = 0;
        right[0] = 1;
        left[0] = 0;
        int op,X,Y;
        bool inv = false;
        while (m--)
        {
            scanf("%d",&op);
            if (op == 4)
            {
                inv = !inv;
                continue;
            }
            scanf("%d%d",&X,&Y);
            if (op != 3 && inv)
                op = 3 - op;
            if (op == 1 && X == left[Y])
                continue;
            if (op == 2 && X == right[Y])
                continue;
            int LX = left[X],RX = right[X],LY = left[Y],RY = right[Y];
            if (op == 1)
            {
                link(LX,RX);
                link(LY,X);
                link(X,Y);
                continue;
            }
            if (op == 2)
            {
                link(LX,RX);
                link(Y,X);
                link(X,RY);
                continue;
            }
            if (right[X] == Y)
            {
                link(LX,Y);
                link(Y,X);
                link(X,RY);
                continue;
            }
            if (right[Y] == X)
            {
                link(LY,X);
                link(X,Y);
                link(Y,RX);
                continue;
            }
            link(LX,Y);
            link(Y,RX);
            link(LY,X);
            link(X,RY);
        }
        int b = 0;
        long long odd = 0,even = 0; 
        for (int i = 1; i <= n; i++)
        {
            b = right[b];
            if (i % 2 == 0)
                even += b;
            else
                odd += b;
        }
        long long ans = odd;
        if (inv)
           ans = even; 
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}
