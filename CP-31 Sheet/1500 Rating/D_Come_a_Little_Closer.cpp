#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int f(int w, int h, int n)
{
    if (w * h >= n)
        return w * h;
    int op1 = max(w, (n / h + (n % h != 0))) * h, op2 = max(h, (n / w + (n % w != 0))) * w;
    return min(op1, op2);
}
void marwan()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> a, b;
    for (auto &[x, y] : v)
    {
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(all(a));
    sort(all(b));
    int afm = a[0], asem = a[1], afx = a.back(), asx = a[n - 2];
    int bfm = b.front(), bsem = b[1], bfx = b.back(), bsx = b[n - 2];
    int ans = (afx - afm + 1) * (bfx - bfm + 1);
    for (auto [x, y] : v)
    {
        int mnx = afm, mxx = afx;
        int mny = bfm, mxy = bfx;
        if (x == afm)
            mnx = asem;
        if (x == afx)
            mxx = asx;
        if (y == bfm)
            mny = bsem;
        if (y == bfx)
            mxy = bsx;

        ans = min(ans, f(mxx - mnx + 1, mxy - mny + 1, n));
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}