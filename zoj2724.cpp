/************************************************************************
    > File Name:    zoj2724.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月14日 星期二 19时39分38秒
************************************************************************/

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 200;

struct data{
    char msg[MAXN];
    int para,prio,time;
};

bool operator<(const data &a,const data &b)
{
    if (a.prio != b.prio)
        return a.prio > b.prio;
    return a.time > b.time;
}

int main()
{
    priority_queue<data> q;
    char str[MAXN];
    int time(0);
    while (scanf("%s",str) == 1)
    {
        ++time;
        if (str[0] == 'P')
        {
            data t;
            scanf("%s%d%d",t.msg,&t.para,&t.prio);
            t.time = time;
            q.push(t);
        }
        else
        {
            if (q.empty())
            {
                printf("EMPTY QUEUE!\n");
                continue;
            }
            data t = q.top();
            q.pop();
            printf("%s %d\n",t.msg,t.para); 
        }
    }
    return 0;
}
