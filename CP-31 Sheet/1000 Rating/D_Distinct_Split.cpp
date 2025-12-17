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
    string s;
    cin >> s;
    vector<int> a(n, 0), b(n, 0);
    set<int> x, y;
    for (int i = 0; i < n; i++)
    {
        x.insert(s[i]);
        a[i] = x.size();
        y.insert(s[n - 1 - i]);
        b[n - 1 - i] = y.size();
    }
    b.push_back(0);
    // for (auto vl : a)
    //     cout << vl << " ";
    // cout << endl;
    // for (auto vl : b)
    //     cout << vl << " ";
    // cout << endl;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] + b[i + 1]);
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