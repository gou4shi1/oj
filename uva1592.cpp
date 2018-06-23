/************************************************************************
    > File Name:    UVa1592.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月27日 星期日 19时54分56秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

typedef pair<int,int> Pair;

map<string,int> IDcache;

const int MAXN = 100;
const int MAXR = 10000 + 5;
const int MAXC = 10 + 5; 

int num;
int database[MAXR][MAXC];

int ID(const char *word)
{
    string str(word);
    if (!IDcache.count(str))
        IDcache[str] = num++;
    return IDcache[str];
}

int main()
{
    int n,m;
    char line[MAXN];
    char *word;
    while (scanf("%d%d%*c",&n,&m) == 2)
    {
        for (int r = 0; r != n; ++r)
        {
            scanf("%[^\n]%*c",line);
            int c(0);
            word = strtok(line,",");
            while (word != NULL)
            {
                database[r][c] = ID(word);
                ++c;
                word = strtok(NULL,",");
            }
        }
        int r1,r2;
        bool PNF(true);
        for (int c1 = 0; c1 != m; ++c1)
            for (int c2 = c1 + 1; c2 != m; ++c2)
            {
                if (!PNF)
                    break;
                map<Pair,int> Paircache;
                Pair temp;
                for (int r = 0; r != n; ++r)
                {
                    temp = make_pair(database[r][c1],database[r][c2]);
                    if (!Paircache.count(temp))
                        Paircache[temp] = r;
                    else
                    {
                        r1 = Paircache[temp];
                        r2 = r;
                        PNF = false;
                        break;
                    }
                }
                if (!PNF)
                    printf("NO\n%d %d\n%d %d\n",r1 + 1,r2 + 1,c1 + 1,c2 + 1);
            }
        if (PNF)
            puts("YES");
    }
    return 0;
}
