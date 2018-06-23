/************************************************************************
    > File Name:    UVa156.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月27日 星期日 14时09分11秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

map<string,int> cnt;
vector<string> words;

string repr(const string &s)
{
    string ans = s;
    for (int i = 0; i != ans.length(); ++i)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s[0] == '#')
            break;
        words.push_back(s);
        string r = repr(s);
        if (!cnt.count(r))
            cnt[r] = 0;
        ++cnt[r];
    }
    vector<string> ans;
    for (int i = 0; i != words.size(); ++i)
        if (cnt[repr(words[i])] == 1)
            ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
    for (int i = 0; i != ans.size(); ++i)
        cout << ans[i] << "\n";
    return 0;
}
