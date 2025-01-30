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
bool ok(map<int, int> &m, int sum)
{
    if (sum < m.begin()->first)
        return false;
    if (m.find(sum) != m.end())
    {
        m[sum]--;
        if (m[sum] <= 0)
            m.erase(sum);
        return true;
    }
    return ok(m, sum / 2) and ok(m, sum / 2 + (sum % 2 != 0));
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    sort(all(v));
    if (ok(m, accumulate(all(v), 0ll)))
        yes;
    else
        no;
    // cout << accumulate(all(v), 0ll) / 4 << endl;
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