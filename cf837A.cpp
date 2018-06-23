/************************************************************************
* File Name : cf837A.cpp
* Purpose : water
* Creation Date : 2017年08月13日
* Last Modified : 2017年08月13日 星期日 13时53分52秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main() {
    char s[233];
    int ans = 0;
    while (~scanf("%s", s)) {
        int cnt = 0, len = strlen(s);
        for (int i = 0; i < len; ++i)
            cnt += (s[i] >= 'A' && s[i] <= 'Z') ? 1 : 0;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}

