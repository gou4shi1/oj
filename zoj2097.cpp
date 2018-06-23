/************************************************************************
    > File Name:    zoj2097.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月25日 星期六 20时22分16秒
************************************************************************/

#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 10;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

struct data{
    int x,y,s,c;
    data (int X = 0,int Y = 0,int S = 0,int C = 0) : x(X),y(Y),s(S),c(C) {}
};

bool operator < (const data &a,const data &b) { return a.c > b.c; }

int a[MAXN][MAXN];
bool flag[MAXN][MAXN][MAXN];

int main()
{
    int x1,y1,x2,y2;
    while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2) == 4 && x1 != 0)
    {
        memset(flag,0,sizeof(flag));
        for (int i = 1; i <= 8; ++i)
            for (int j = 1; j <= 8; ++j)
                scanf("%d",&a[i][j]);
        priority_queue<data> q;
        q.push(data(x1,y1,1,0));
        data p;
        while (!q.empty())
        {
            p = q.top();
            q.pop();
            if (p.x == x2 && p.y == y2)
                break;
            for (int i = 0; i != 4; ++i)
            {
                data pp(p.x + dx[i],p.y + dy[i],p.s,p.c);
                if (pp.x < 1 || pp.x > 8 || pp.y < 1 || pp.y > 8)
                    continue;
                pp.c += p.s * a[pp.x][pp.y];
                pp.s = (p.s * a[pp.x][pp.y]) % 4 + 1;
                if (flag[pp.x][pp.y][pp.s])
                    continue;
                flag[pp.x][pp.y][pp.s] = true;
                q.push(pp);
            }
        }
        printf("%d\n",p.c);
    }
    return 0;
}
