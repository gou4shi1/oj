/************************************************************************
    > File Name:    UVa10815.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月27日 星期日 13时37分26秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <sstream>

using namespace std;

set<string> dict;

int main()
{
    string s,buf;
    while (cin >> s)
    {
        for (int i = 0; i != s.length(); ++i)
        {
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        stringstream ss(s);
        while (ss >> buf)
            dict.insert(buf);
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
        cout << *it << "\n";
    return 0;
}

