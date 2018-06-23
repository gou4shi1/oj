/************************************************************************
    > File Name:    zoj1091.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月25日 星期六 17时26分31秒
************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 10;
const int dx[] = {-2,-1,1,2,2,1,-1,-2};
const int dy[] = {-1,-2,-2,-1,1,2,2,1};

struct data{
    int x,y,d;
    data(int X = 0,int Y = 0,int D = 0) : x(X),y(Y),d(D) {}
};

bool flag[MAXN][MAXN];

int main()
{
    char ch1,ch2;
    int col1,col2,row1,row2;
    while (cin >> ch1 >> row1 >> ch2 >> row2)
    {
        col1 = ch1 - 'a' + 1; 
        col2 = ch2 - 'a' + 1; 
        queue<data> q;
        q.push(data(col1,row1,0));
        data p;
        memset(flag,0,sizeof(flag));
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (p.x == col2 && p.y == row2)
                break;
            for (int i = 0; i != 8; ++i)
            {
                data pp(p.x + dx[i],p.y + dy[i],p.d + 1);
                if (pp.x < 1 || pp.x > 8 || pp.y < 1 || pp.y > 8 || flag[pp.x][pp.y])
                   continue;
                flag[pp.x][pp.y] = true;
                q.push(pp); 
            }
        }
        cout << "To get from " << ch1 << row1 << " to " << ch2 << row2 << " takes " << p.d << " knight moves." << endl;
    }
    return 0;
}
