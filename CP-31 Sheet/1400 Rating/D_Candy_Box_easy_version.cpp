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
    vector<int> v(n), fq;
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    for (auto [x, y] : m)
    {
        fq.push_back(y);
    }
    sort(all(fq), greater<int>());
    int ans = 0, x = fq[0];
    for (int i = 0; i < fq.size(); i++)
    {
        x = min(x, fq[i]);
        ans += x;
        x--;
        if (x <= 0)
            break;
    }
    cout << ans << endl;
    // cout << accumulate(all(s), 0ll) << endl;
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