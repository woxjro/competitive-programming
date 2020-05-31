#include <bits/stdc++.h>
#define int long long
using namespace std;

//ABC038 C-単調増加
void solve()
{

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;

    int r = 0;
    for (int l = 0; l < n; l++)
    {
        if (l == r)
            r++;
        for (; r < n && a[r - 1] < a[r]; r++)
            ;
        ans += r - l;
    }

    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
