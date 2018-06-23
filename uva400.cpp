/************************************************************************
    > File Name:    UVa400.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月27日 星期日 18时44分42秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAXCOL = 60;
const int MAXN = 100 + 5;

string filenames[MAXN];

void print(const string &s,int len,char extra)
{
    cout << s;
    for (int i = 0; i != len-s.length(); ++ i)
        cout << extra;
}

int main()
{
    int n;
    while (cin >> n)
    {
        int M = 0;
        for (int i = 0; i != n; ++i)
        {
            cin >> filenames[i];
            M = max(M,(int)filenames[i].length());
        }
        int cols = (MAXCOL - M) / (M + 2) + 1,rows = (n - 1) / cols + 1;
        print("",60,'-');
        cout << "\n";
        sort(filenames,filenames + n);
        for (int r = 0; r != rows; ++r)
        {
            for (int c = 0; c != cols; ++c)
            {
                int idx = c * rows + r;
                if (idx < n)
                    print(filenames[idx],c == cols-1 ? M : M+2,' ');
            }
            cout << "\n";
        }
    }
    return 0;
}
