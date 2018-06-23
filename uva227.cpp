/************************************************************************
    > File Name:    UVa227.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月09日 星期三 20时19分54秒
************************************************************************/

#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10;
const char direction[] = "ARBL";
const int dy[] = {0,1,0,-1};
const int dx[] = {-1,0,1,0};

char str[MAXN][MAXN];
char mymove[1000000];

int main()
{
    int kase = 0;
    while (scanf("%[^\n]%*c",str[0]) && str[0][0] != 'Z')
    {
        for (int i = 1; i <= 4; ++i)
            scanf("%[^\n]%*c",str[i]);
        int x,y;
        for (int i = 0; i != 5; ++i)
            for (int j = 0; j != 5; ++j)
                if (str[i][j] == ' ')
                {
                    x = i;
                    y = j;
                }
        int x2,y2;
        bool error = false;
        scanf("%[^0]%*c%*c",mymove);
        int len = strlen(mymove);
        for (int i = 0; i != len; ++i)
        {
            if (mymove[i] == '\n')
                continue;
            for (int j = 0; j != 4; ++j)
                if (mymove[i] == direction[j])
                {
                    x2 = x + dx[j];
                    y2 = y + dy[j];
                    break;
                }
            if (x2 < 0 || x2 > 4 || y2 < 0 || y2 > 4)
            {
                error = true;
                continue;
            }
            str[x][y] = str[x2][y2];
            str[x2][y2] = ' ';
            x = x2;
            y = y2;
        }
        if (kase != 0)
            printf("\n");
        printf("Puzzle #%d:\n",++kase);
        if (error)
        {
            printf("This puzzle has no final configuration.\n");
            continue;
        }
        for (int i = 0; i != 5; ++i)
        {
            for (int j = 0; j != 4; ++j)
                printf("%c ",str[i][j]);
            printf("%c\n",str[i][4]);
        }
    }
    return 0;
}
