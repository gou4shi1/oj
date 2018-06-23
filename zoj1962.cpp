/************************************************************************
    > File Name:    zoj1962.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月26日 星期日 21时24分30秒
************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int MOD = 10000;
const int DLEN = 4;

struct BigInt{
    int a[100],len;
    BigInt()
    {
        memset(a,0,sizeof(a));
        len = 1;
    }
    BigInt(const char s[])
    {
        memset(a,0,sizeof(a));
        int L = strlen(s);
        len = L / DLEN;
        if (L % DLEN)
            ++len;
        int index = 0;
        for (int i = L - 1; i >= 0; i -= DLEN)
        {
            int t(0),k(i - DLEN + 1);
            if (k < 0)
                k = 0;
            for (int j = k; j <= i; ++j)
                t = t*10 + s[j]-'0';
            a[index++] = t;
        }
    }
};

BigInt operator + (const BigInt &x,const BigInt &y) 
{
    BigInt res;
    res.len = max(x.len,y.len);
    for (int i = 0; i != res.len; ++i)
    {
        res.a[i] += ((i < x.len) ? x.a[i] : 0) + ((i < y.len) ? y.a[i] : 0);
        res.a[i + 1] += res.a[i] / MOD;
        res.a[i] %= MOD;
    }
    if (res.a[res.len] > 0)
        ++res.len;
    return res;
}

bool operator == (const BigInt &x,const BigInt &y) 
{
    if (x.len != y.len)
        return false;
    for (int i = x.len-1; i >= 0; --i)
        if (x.a[i] != y.a[i])
            return false;
    return true;
}

bool operator < (const BigInt &x,const BigInt &y) 
{
    if (x.len != y.len)
        return x.len < y.len;
    for (int i = x.len-1; i >= 0; --i)
        if (x.a[i] != y.a[i])
            return x.a[i] < y.a[i];
    return false;
}

bool operator <= (const BigInt &x,const BigInt &y) 
{
    return (x == y) || (x < y);
}

int main()
{
    char a_str[MAXN],b_str[MAXN];
    while (scanf("%s%s",a_str,b_str) == 2 && b_str[0] != '0')
    {
        BigInt a(a_str),b(b_str);
        BigInt fn("1"),fn_1("1"),temp;
        while (fn < a)
        {
            temp = fn;
            fn = fn_1 + fn;
            fn_1 = temp;
        }
        int ans(0);
        while (fn <= b)
        {
            ++ans;
            temp = fn;
            fn = fn_1 + fn;
            fn_1 = temp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
