/************************************************************************
    > File Name:    zoj1067.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月26日 星期日 23时49分30秒
************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 105;
const int MAXM = 16;

int x[MAXN],y[MAXN],z[MAXN];

int main()
{
    for (int i = 0; i != MAXM; ++i)
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    int a,b,c;
    while (scanf("%d%d%d",&a,&b,&c) == 3 && a != -1)
    {
        int min(0);
        for (int i = 1; i != MAXM; ++i)
            if (((a-x[i])*(a-x[i])+(b-y[i])*(b-y[i])+(c-z[i])*(c-z[i])) < ((a-x[min])*(a-x[min])+(b-y[min])*(b-y[min])+(c-z[min])*(c-z[min])))
                min = i;
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a,b,c,x[min],y[min],z[min]);
    }
    return 0;
}
