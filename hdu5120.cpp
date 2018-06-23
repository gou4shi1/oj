/************************************************************************
* File Name : hdu5120.cpp
* Purpose : cg
* Creation Date : 2017年10月14日
* Last Modified : 2017年10月14日 星期六 15时50分05秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;
const double PI = acos(-1.0);

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

// vector
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))
typedef int itn;

int sgn(double x) {
    return fabs(x)<EPS ? 0 : (x<0 ? -1 : 1);
}

struct Point {
    double x, y;
};

Point operator - (const Point &a, const Point &b) {
    return {a.x-b.x, a.y-b.y};
}

double operator * (const Point &a, const Point &b) {
    return a.x*b.x + a.y*b.y;
}

double dist(Point a,Point b) {
    return sqrt((a-b)*(a-b));
}

double inter(Point c1, double r1, Point c2, double r2) {
    double d = dist(c1,c2);
    if(r1 + r2 < d + EPS)
        return 0;
    if(d < fabs(r1 - r2) + EPS) {
        double r = min(r1,r2);
        return PI*r*r;
    }
    double x = (d*d + r1*r1 - r2*r2) / (2*d);
    double t1 = acos(x / r1);
    double t2 = acos((d - x)/r2);
    return r1*r1*t1 + r2*r2*t2 - d*r1*sin(t1);
}

double uni(Point c1, double r1, Point c2, double r2) {
    return PI*r1*r1 + PI*r2*r2 - inter(c1, r1, c2, r2);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    for (int Ti = 1; Ti <= T; ++Ti) {
        int r, R, x1, y1, x2, y2;
        scanf("%d%d%d%d%d%d", &r, &R, &x1, &y1, &x2, &y2);
        Point c1 = {(double)x1, (double)y1}, c2 = {(double)x2, (double)y2};
        double dis = dist(c1, c2), ans;
        if (dis >= R+R) {
            ans = 0;
        } else if (dis >= R+r) {
            ans = inter(c1, R, c2, R);
        } else {
            if (r+r < R-r) {
                if (dis >= r+r)
                    ans = inter(c1, R, c2, R) - inter(c1, R, c2, r) - inter(c1, r, c2, R);
                else 
                    ans = inter(c1, R, c2, R) - uni(c1, r, c2, r);
            } else {
                if (dis >= r+r) {
                    ans = inter(c1, R, c2, R) - inter(c1, R, c2, r) - inter(c1, r, c2, R);
                } else if (dis >= R-r) {
                    ans = uni(c1, R, c2, R)-uni(c1, r, c2, r) - (uni(c1, R, c2, R)-uni(c1, r, c2, R)) - (uni(c1, R, c2, R)-uni(c1, R, c2, r));
                } else {
                    ans = inter(c1, R, c2, R) - uni(c1, r, c2, r);
                }
            }
        }
        printf("Case #%d: %.6f\n", Ti, ans);
    }

    return 0;
}

