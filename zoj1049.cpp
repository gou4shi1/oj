/************************************************************************
    > File Name:    zoj1049.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月27日 星期一 00时39分47秒
************************************************************************/

#include <cstdio>
#include <cmath>

using namespace std;

#define pi acos(-1.0)

const int MAXN = 1005;

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        double area = pi*(x*x+y*y)/2;
        printf("Property %d: This property will begin eroding in year %d.\n",i,(int)ceil(area/50));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
