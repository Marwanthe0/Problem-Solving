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
int p[N], pf[N];
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v), greater<int>());
    memset(p, 0, sizeof(p));
    memset(pf, 0, sizeof(pf));
    vector<pair<int, int>> r;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        r.push_back({a, b});
        p[a - 1]++, p[b]--;
    }
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + p[i - 1];
        m[pf[i]].push_back(i);
    }
    vector<int> idx, ans(n);
    for (auto vl : m)
    {
        for (auto val : vl.second)
            idx.push_back(val);
    }
    reverse(all(idx));
    int count = 0;
    for (auto vl : idx)
    {
        ans[vl - 1] = v[count++];
    }
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + ans[i - 1];
    }
    int last = 0;
    for (auto [x, y] : r)
    {
        last += pre[y] - pre[x - 1];
    }
    cout << last << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}