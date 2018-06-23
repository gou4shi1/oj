/************************************************************************
    > File Name:    UVa1587.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月13日 星期日 13时36分23秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10;

int main()
{
    int width[MAXN],height[MAXN];
    bool used[MAXN];
    while (scanf("%d%d",&width[1],&height[1]) == 2)
    {
        bool possible = false;
        for (int i = 2; i <= 6; ++i)
            scanf("%d%d",&width[i],&height[i]);
        for (int i = 1; i <= 6; ++i)
            if (width[i] > height[i])
                swap(width[i],height[i]);
        for (int i = 1; i <=5; ++i)
            for (int j = i + 1; j <= 6; ++j)
                if ((width[i] == width[j]) && (height[i] == height[j]))
                {
                    memset(used,false,sizeof(used));
                    used[i] = used [j] = true;
                    int box_x = 0,box_y = width[i],box_z = height[i];
                    for (int k = 1; k <= 6; ++k)
                    {
                        if (used[k])
                            continue;
                        if ((width[k] == box_y) || (height[k] == box_y))
                        {
                            if (width[k] == box_y)
                                box_x = height[k];
                            else
                                box_x = width[k];
                            used[k] = true;
                            for (int l = 1; l <= 6; ++l)
                            {
                                if (used[l])
                                    continue;
                                if ((width[l] == width[k]) && (height[l] == height[k]))
                                {
                                    used[l] = true;
                                    for (int m = 1; m <= 6; ++m)
                                    {
                                        if (used[m])
                                            continue;
                                        if (((width[m] == box_x) && (height[m] == box_z)) || ((width[m] == box_z) && (height[m] == box_x)))
                                        {
                                            used[m] = true;
                                            for (int n = 1; n <= 6; ++n)
                                            {
                                                if (used[n])
                                                    continue;
                                                if ((width[n] == width[m]) && (height[n] == height[m]))
                                                    possible = true;
                                            }
                                            used[m] = false;
                                        }
                                    }
                                    used[l] = false;
                                }
                            }
                            used[k] = false;
                        }
                    }
                }
        if (possible)
            puts("POSSIBLE");
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}


