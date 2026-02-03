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
void marwan()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v;
    for (int i = k - 1; i >= 1; i--)
    {
        v.push_back(k - i);
    }
    v.push_back(0);
    for (int i = k + 1; i <= n; i++)
        v.push_back(i - k);
    sort(all(v));
    for (int i = 1; i < v.size(); i++)
        v[i] = v[i - 1] + v[i];
    for (int i = 0; i < min((int)v.size(), (int)100); i++)
        cerr << v[i] << " ";
    cerr << endl;
    auto it = lower_bound(all(v), m);
    if (*it != m)
        it--;
    cout << it - v.begin() + 1 << endl;
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