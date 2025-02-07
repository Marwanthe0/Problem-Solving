#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000009
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> op(N, 0), ans(N, 0);
void marwan()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<pair<pair<int, int>, int>> kk(k);
    for (auto &vl : kk)
    {
        cin >> vl.first.first >> vl.first.second >> vl.second;
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        op[a]++, op[b + 1]--;
    }
    for (int i = 1; i < N; i++)
    {
        op[i] += op[i - 1];
    }
    for (int i = 1; i <= k; i++)
    {
        // cout << op[i] << " ";
        kk[i - 1].second *= op[i];
    }
    cout << endl;
    for (auto vl : kk)
    {
        int a = vl.first.first, b = vl.first.second, c = vl.second;
        ans[a] += c, ans[b + 1] -= c;
    }
    for (int i = 1; i < N; i++)
        ans[i] += ans[i - 1];
    for (int i = 0; i < n; i++)
    {
        // cout << ans[i + 1] << " ";
        cout << v[i] + ans[i + 1] << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}