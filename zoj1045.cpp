/************************************************************************
    > File Name:    zoj1045.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月26日 星期日 23时25分33秒
************************************************************************/

#include <cstdio>

using namespace std;

const double EPS = 1E-8;

int main()
{
    double c;
    while (scanf("%lf",&c) == 1 && c)
    {
        double d(0.5);
        int n(1);
        while ((c-d) > EPS)
        {
            ++n;
            d += (double)1/(n+1);
        }
        printf("%d card(s)\n",n);
    }
    return 0;
}
