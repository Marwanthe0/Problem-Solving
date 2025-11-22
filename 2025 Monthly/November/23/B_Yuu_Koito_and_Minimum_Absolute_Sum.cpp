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
    vector<int> v(n), b(n - 1), c;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] > 0)
            c.push_back(v[i]);
    }
    if (c.empty())
    {
        cout << 0 << endl;
        for (auto vl : v)
            cout << 0 << " ";
        cout << endl;
        return;
    }
    int sum = 0;
    for (int i = 1; i < c.size(); i++)
        sum += c[i] - c[i - 1];
    // cout << sum << endl;
    if (v[0] == -1 && v[n - 1] == -1)
    {
        v[0] = 0, v[n - 1] = 0;
    }
    else if (v[0] == -1)
    {
        v[0] = v[n - 1];
    }
    else if (v[n - 1] == -1)
    {
        v[n - 1] = v[0];
    }
    for (int i = 1; i < n - 1; i++)
        if (v[i] == -1)
            v[i] = 0;
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += (v[i] - v[i - 1]);
    cout << abs(ans) << endl;
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
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