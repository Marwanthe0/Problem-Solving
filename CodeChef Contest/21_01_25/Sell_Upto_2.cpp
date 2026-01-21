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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = 0;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        if (!ms.empty() && *ms.begin() < v[i])
        {
            ms.insert(v[i]);
            ms.erase(ms.begin());
        }
        ms.insert(v[i]);
        // for (auto vl : ms)
        //     cerr << vl << " ";
        // cerr << endl;
    }
    cout << accumulate(all(ms), 0ll) << endl;
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