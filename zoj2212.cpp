/************************************************************************
    > File Name:    zoj2212.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月06日 星期一 23时38分33秒
************************************************************************/

#include <string>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1000;

struct data
{
    int id,period,next;
};

bool operator < (const data &a,const data &b)
{
    if (a.next != b.next)
        return a.next > b.next;
    return a.id > b.id;
}

int main()
{
    char str[MAXN];
    data temp;
    priority_queue<data> q;
    while (scanf("%s",str) == 1 && str[0] != '#')
    {
        scanf("%d%d",&temp.id,&temp.period);
        temp.next = temp.period;
        q.push(temp);
    }
    int k;
    scanf("%d",&k);
    while (k--)
    {
        temp = q.top();
        printf("%d\n",temp.id);
        temp.next += temp.period;
        q.pop();
        q.push(temp);
    }
    return 0;
}
