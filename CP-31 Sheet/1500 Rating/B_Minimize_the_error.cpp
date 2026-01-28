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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n), y(n);
    for (auto &vl : x)
        cin >> vl;
    for (auto &vl : y)
        cin >> vl;
    multiset<int, greater<int>> ms;
    for (int i = 0; i < n; i++)
        if (x[i] != y[i])
            ms.insert(abs(x[i] - y[i]));
    a += b;
    vector<int> v(all(ms)), aa;
    int sum = accumulate(all(v), 0ll);
    if (a >= sum)
    {
        cout << ((a - sum) % 2) << endl;
        return;
    }
    n = v.size();
    for (int i = 0; i < n; i++)
    {
        aa.push_back((i + 1) * (v[i] - ((i != (n - 1)) ? v[i + 1] : 0)));
        if (i)
            aa[i] += aa[i - 1];
        //cerr << aa[i] << " ";
    }
    //cerr << endl;
    auto it = lower_bound(all(aa), a) - aa.begin();
    // it--;
    //cerr << it << endl;
    int xs = 0;
    for (int i = 0; i < it; i++)
    {
        xs += v[i] - v[it];
        v[i] = v[it];
    }
    for (int i = 0; i < a - xs; i++)
    {
        v[i % (it + 1)]--;
    }
    int ans = 0ll;
    for (auto vl : v)
    {
        ans += (vl * vl);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}