/************************************************************************
* File Name : cf837F.cpp
* Purpose : binary search
* Creation Date : 2017年08月15日
* Last Modified : 2017年08月15日 星期二 19时06分41秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 200000 + 10;
const long long MAXK = 1E18;
const int INF = 0x3f3f3f3f;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

LL mult_ok(LL x, LL y) {
    LL p = x * y;
    return !x || p/x == y;
}

int n;

struct Matrix {
    static const int N = 11;
    LL data[N][N];

    Matrix(int type = 0) {
        switch (type) {
            case 0 :
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= n; ++j)
                        data[i][j] = 0;
                break;
            case 1 :
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= n; ++j)
                        if (i == j)
                            data[i][j] = 1;
                        else
                            data[i][j] = 0;
                break;
            case 2:
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= n; ++j)
                        if (i >= j)
                            data[i][j] = 1;
                        else
                            data[i][j] = 0;
        }
    }

    Matrix operator *(const Matrix &rhs) const {
        Matrix ret;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k) {
                    if (!mult_ok(data[i][k], rhs.data[k][j]))
                        ret.data[i][j] = MAXK;
                    else {
                        ret.data[i][j] += data[i][k]*rhs.data[k][j];
                        if (ret.data[i][j] < 0)
                            ret.data[i][j] = MAXK;
                    }
                }

        return ret;
    }

    Matrix operator ^(LL m) const {
        Matrix ret(1);

        Matrix temp = *this;
        while (m) {
            if (m&1)
                ret = ret * temp;
            temp = temp * temp;
            m >>= 1;
        }
        return ret;
    }

    void print() {
        printf("Matrix:\n");
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                printf("%lld ", data[i][j]);
            printf("\n");
        }
    }
};

LL a[MAXN];
LL k;

bool ge(LL m) {
    Matrix A(2);
    A = A^m;
    //A.print();
    for (int i = 1; i <= n; ++i) {
        LL x = 0;
        for (int j = 1; j <= n; ++j) {
            if (!mult_ok(A.data[i][j], a[j]))
                return true;
            x += A.data[i][j] * a[j];
            if (x >= k || x < 0)
                return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%d" LLD, &n, &k);
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        if (m || t)
            a[++m] = t;
    }
    n = m;

    for (int i = 1; i <= n; ++i)
        if (a[i] >= k) {
            puts("0");
            return 0;
        }

    if (n >= 10) {
        LL ans = 0;
        while (a[n] < k) {
            ++ans;
            for (int i = 1; i <= n; ++i) {
                a[i] += a[i-1];
                if (a[i] >= k) {
                    a[n] = a[i];
                    break;
                }
            }
        }
        printf(LLD "\n", ans);
    } else {
        LL l = 1, r = MAXK;
        while (l < r) {
            LL m = (l + r) >> 1;
            if (ge(m))
                r = m;
            else
                l = m + 1;
        }
        printf(LLD "\n", l);
    }

    return 0;
}

