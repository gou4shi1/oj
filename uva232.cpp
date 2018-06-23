/************************************************************************
    > File Name:    UVa232.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月12日 星期六 16时57分27秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10 + 5;

char puzzle[MAXN][MAXN];
bool down[MAXN][MAXN],across[MAXN][MAXN];
int order[MAXN][MAXN];

int main()
{
    int r,c;
    int kase = 0;
    while (scanf("%d",&r) == 1 && r != 0)
    {
        int m = 0;
        memset(down,false,sizeof(down));
        memset(across,false,sizeof(across));
        scanf("%d",&c);
        for (int i = 0; i != r; ++i)
        {
            scanf("%s",puzzle[i]);
            for (int j  = 0; j != c; ++j)
            {
                if (puzzle[i][j] == '*')
                    continue;
                if (i == 0 || puzzle[i - 1][j] == '*')
                    down[i][j] = true;
                if (j == 0 || puzzle[i][j - 1] == '*')
                    across[i][j] = true;
                if (down[i][j] || across[i][j])
                    order[i][j] = ++m;        
            }
        }
        if (kase++ > 0)
            printf("\n");
        printf("puzzle #%d:\n",kase);
        printf("Across\n");
        for (int i = 0; i != r; ++i)
            for (int j = 0; j != c; ++j)
                if (across[i][j])
                {
                    printf("%3d.",order[i][j]);
                    int k = j;
                    while (k != c && puzzle[i][k] != '*')
                        printf("%c",puzzle[i][k++]);
                    printf("\n");
                }
        printf("Down\n");
        for (int i = 0; i != r; ++i)
            for (int j = 0; j != c; ++j)
                if (down[i][j])
                {
                    printf("%3d.",order[i][j]);
                    int k = i;
                    while (k != r && puzzle[k][j] != '*')
                        printf("%c",puzzle[k++][j]);
                    printf("\n");
                }
    }
    return 0;
}
