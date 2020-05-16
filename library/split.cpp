#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;

const int INF = 1e18;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        if (!item.empty())
        {
            elems.push_back(item);
        }
    }
    return elems;
}
void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    // ABC33 C

    string s;
    cin >> s;
    vector<string> svec = split(s, '+');

    int ans = 0;
    for (auto ns : svec)
    {
        if (ns.size() > 1)
        {
            ans += (count(ALL(ns), '0') ? 0 : 1);
        }
        else
        {
            ans += ((ns[0] == '0') ? 0 : 1);
        }
    }
    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
