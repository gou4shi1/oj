/************************************************************************
    > File Name:    zoj1649.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月25日 星期六 18时53分16秒
************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 1000;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

struct data{
    int x,y,t;
    data (int X = 0,int Y = 0,int T = 0) : x(X),y(Y),t(T) {}
};

bool operator < (const data &a,const data &b) { return a.t > b.t; }

char a[MAXN][MAXN];
bool flag[MAXN][MAXN];

int main()
{
    int n,m;
    while (cin >> n >> m)
    {
        priority_queue<data> q;
        memset(flag,0,sizeof(flag));
        for (int i = 0; i != MAXN; ++i)
            flag[0][i] = flag[i][0] = flag[n+1][i] = flag[i][m+1] = true;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 'a')
                {
                    q.push(data(i,j,0));
                    flag[i][j] = true;
                }
                if (a[i][j] != '.' && a[i][j] != 'a' && a[i][j] != 'r' && a[i][j] != 'x')
                    flag[i][j] = true;
            }
        data p;
        while (!q.empty())
        {
            p = q.top();
            q.pop();
            if (a[p.x][p.y] == 'r')
                break;
            for (int i = 0; i != 4; ++i)
            {
                data pp(p.x + dx[i],p.y + dy[i],p.t + 1);
                if (flag[pp.x][pp.y])
                    continue;
                if (a[pp.x][pp.y] == 'x')
                    ++pp.t;
                flag[pp.x][pp.y] = true;
                q.push(pp);
            }
        }
        if (a[p.x][p.y] == 'r')
            cout << p.t << endl;
        else
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
    }
    return 0;
}
