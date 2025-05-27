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
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first + a.second < b.first + b.second; }
void marwan()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pair<int, int>> v(n);
    map<pair<int, int>, int> m;
    for (auto &[x, y] : v)
    {
        cin >> x >> y;
        if (k > 0)
            m[{x, y}]++;
        k--;
    }
    pair<int, int> start = v[a - 1], end = v[b - 1];
    sort(all(v), cmp);
    for (auto vl : v)
        cout << vl.first << " " << vl.second << endl;
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