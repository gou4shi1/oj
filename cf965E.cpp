/************************************************************************
* File Name : cf965E.cpp
* Purpose : tree
* Creation Date : 2018年05月05日
* Last Modified : 2018年05月05日 星期六 22时28分50秒
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

// long long
typedef long long LL;
#ifdef _WIN32
#define lld I64d
#endif

// vector
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))

struct Node {
    Node *_son[26] = {0};
    bool flag = false;

    bool exist(char ch) {
        return _son[ch - 'a'];
    }

    Node* son(char ch) {
        int t = ch - 'a';
        return _son[t] ? _son[t] : (_son[t] = new Node());
    }
};

void add(Node *p, const string &str) {
    int len = str.length();
    for (int i = 0; i < len; ++i)
        p = p->son(str[i]);
    p->flag = true;
}

using Deps = multiset<int>;

void merge(Deps* &a, Deps* &b) {
    if (a->size() < b->size())
        swap(a, b);
    for (auto x: *b)
        a->insert(x);
    delete b;
}

Deps* dfs(Node *p, int d) {
    Deps *deps = new Deps;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (p->exist(ch)) {
            auto _deps = dfs(p->son(ch), d + 1);
            merge(deps, _deps);
        }
    }

    if (p->flag) {
        deps->insert(d);
    } else {
        deps->erase(prev(deps->end()));
        deps->insert(d);
    }

    return deps;
}
/*
void debug(Node *p, string str) {
    if (p->flag)
        cout << str << endl;

    for (int ch = 'a'; ch <= 'z'; ++ch) {
        if (p->exist(ch))
            debug(p->son(ch), str + (char)ch);
    }
}
*/
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    Node *root = new Node;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string str; 
        cin >> str;
        add(root, str);
    }
    //debug(root, string());

    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (root->exist(ch)) {
            auto deps = dfs(root->son(ch), 1);
            ans += accumulate(all(*deps), 0);
            delete deps;
        }
    }

    cout << ans << endl;
    
    return 0;
}

