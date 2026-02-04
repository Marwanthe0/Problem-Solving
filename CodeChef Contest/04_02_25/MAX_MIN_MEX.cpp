#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
vector<int> fact(2e5 + 10);
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for (auto &vl : v)
    {
        cin >> vl;
        s.insert(vl);
    }
    int count = 0;
    for (auto vl : v)
    {
        if (s.count(vl - 1))
            count++;
    }
    // cerr << count << endl;
    int ans = 0ll;
    if (!count)
    {
        cout << (fact[n] % M) << endl;
        return;
    }
    ans = ((count % M) * 2) % M;
    ans = ((ans % M) * (fact[n - 2]) % M) % M;
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x = 1;
    fact[0] = 1;
    for (int i = 1; i <= 2e5; i++)
    {
        fact[i] = ((fact[i - 1] % M) * (i)) % M;
    }
    // for (auto vl : fact)
    //     cout << vl << " ";
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}