/************************************************************************
* File Name : hdu5950.cpp
* Purpose : matrix-quick-power
* Creation Date : 2016年11月08日
* Last Modified : 2017年10月07日 星期六 14时02分01秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <cstdio>

using namespace std;

typedef long long LL;

const LL MOD = 2147493647;
const int N = 7;

const int MATRIX[N][N] = {{1,2,1,0,0,0,0},{1,0,0,0,0,0,0},{0,0,1,4,6,4,1},{0,0,0,1,3,3,1},{0,0,0,0,1,2,1},{0,0,0,0,0,1,1},{0,0,0,0,0,0,1}};

struct Matrix {
    LL data[N][N];

    Matrix(int type = 0) {
        switch (type) {
            case 0 :
                for (int i = 0; i != N; ++i)
                    for (int j = 0; j != N; ++j)
                        data[i][j] = 0;
                break;
            case 1 :
                for (int i = 0; i != N; ++i)
                    for (int j = 0; j != N; ++j)
                        if (i == j)
                            data[i][j] = 1;
                        else
                            data[i][j] = 0;
                break;
        }
    }

    Matrix(const int m[][N]) {
        for (int i = 0; i != N; ++i)
            for (int j = 0; j != N; ++j)
                data[i][j] = m[i][j];
    }

    Matrix operator *(const Matrix &rhs) const {
        Matrix ret;

        for (int i = 0; i != N; ++i)
            for (int j = 0; j != N; ++j)
                for (int k = 0; k != N; ++k) {
                    ret.data[i][j] += (LL)data[i][k]*rhs.data[k][j] % MOD;
                    if (ret.data[i][j] >= MOD)
                        ret.data[i][j] -= MOD;
                }

        return ret;
    }

    Matrix operator ^(LL n) const {
        Matrix ret(1);

        Matrix temp = *this;
        while (n) {
            if (n&1)
                ret = ret * temp;
            temp = temp * temp;
            n >>= 1;
        }
        return ret;
    }

    void print() {
        printf("Matrix:\n");
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j)
                printf("%lld ", data[i][j]);
            printf("\n");
        }
    }
};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        Matrix m(MATRIX);

        if (n == 1) {
            printf("%d\n", a);
            continue;
        }
        if (n == 2) {
            printf("%d\n", b);
            continue;
        }

        Matrix mm = m^(n-2);
        int vec[N];
        vec[0] = b;
        vec[1] = a;
        vec[2] = 81;
        vec[3] = 27;
        vec[4] = 9;
        vec[5] = 3;
        vec[6] = 1;

        LL ans = 0;
        for (int i = 0; i != N; ++i) {
            ans += (LL)mm.data[0][i]*vec[i] % MOD;
            if (ans >= MOD)
                ans -= MOD;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
