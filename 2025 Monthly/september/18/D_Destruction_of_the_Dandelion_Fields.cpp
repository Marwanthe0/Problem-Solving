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
void marwan()
{
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            a.push_back(x);
        else
            b.push_back(x);
    }
    if (a.empty())
        cout << 0 << endl;
    else
    {
        sort(all(a));
        reverse(all(a));
        int ans = accumulate(all(b), 0ll);
        for (int i = 0; i < ((a.size() / 2) + (a.size() % 2)); i++)
            ans += a[i];
        cout << ans << endl;
    }
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