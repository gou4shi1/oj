/************************************************************************
    > File Name:    UVa136.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月27日 星期日 17时03分56秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;

const int coeff[3] = {2,3,5};
const int N = 1500;

int main()
{
    priority_queue<LL,vector<LL>,greater<LL> > pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for (int i = 1; i != N; ++i)
    {
        LL x = pq.top();
        pq.pop();
        for (int j = 0; j != 3; ++j)
        {
            LL x2 = x * coeff[j];
            if (!s.count(x2))
            {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    cout << "The 1500'th ugly number is " << pq.top() << ".\n";
    return 0;
}
