/************************************************************************
* File Name : bzoj1146_dataMaker.cpp
* Purpose : dataMaker of bzoj1146
* Creation Date : 2016年10月02日
* Last Modified : 2016年10月02日 星期日 15时47分39秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <ctime>

const int MAXN = 80000;
const int MAXM = 1E8;

inline void randomize() {
    srand(time(0));
}

inline int random(int l, int r) {
    return l + rand()%(r-l+1);
}

int main() {
    randomize();
    int n = random(1, MAXN), q  = random(1, MAXN);
    printf("%d %d\n", n, q);
    for (int i = 1; i <= n-1; ++i)
        printf("%d ", random(1, MAXM));
    printf("%d\n", random(1, MAXM));
    for (int i = 2; i <= n; ++i)
        printf("%d %d\n", random(1, i-1), i);
    while (q--) {
        int type = random(0, 5);
        if (!type)
            printf("0 %d %d\n", random(1, n), random(1, MAXM));
        else
            printf("%d %d %d\n", random(1, n<100 ? n : 100), random(1, n), random(1, n));
    }
    return 0;
}
