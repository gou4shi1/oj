/************************************************************************
    > File Name:    zoj1940.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月25日 星期六 19时38分44秒
************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100;

const int dx[] = {0,-1,0,1,0,0};
const int dy[] = {-1,0,1,0,0,0};
const int dz[] = {0,0,0,0,-1,1};

struct data{
    int x,y,z,t;
    data(int X = 0,int Y = 0,int Z = 0,int T = 0) : x(X),y(Y),z(Z),t(T) {} 
};

char a[MAXN][MAXN][MAXN];
bool flag[MAXN][MAXN][MAXN];

int main()
{
    int L,R,C;
    while (cin >> L >> R >> C && L != 0)
    {
        queue<data> q;
        memset(flag,0,sizeof(flag));
        for (int i = 1; i <= L; ++i)
            for (int j = 1; j <= R; ++j)
                for (int k = 1; k <= C; ++k)
                {
                    cin >> a[j][k][i];
                    if (a[j][k][i] == 'S')
                        q.push(data(j,k,i,0));
                    if (a[j][k][i] == '#')
                        flag[j][k][i] = true;
                }
        data p;
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (a[p.x][p.y][p.z] == 'E')
                break;
            for (int i = 0; i != 6; ++i)
            {
                data pp(p.x + dx[i],p.y + dy[i],p.z + dz[i],p.t + 1);
                if (pp.x < 1 || pp.x > R)
                    continue;
                if (pp.y < 1 || pp.y > C)
                    continue;
                if (pp.z < 1 || pp.z > L)
                    continue;
                if (flag[pp.x][pp.y][pp.z])
                    continue;
                flag[pp.x][pp.y][pp.z] = true;
                q.push(pp);
            }
        }
        if (a[p.x][p.y][p.z] == 'E')
            cout << "Escaped in " << p.t << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }
    return 0;
}
