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
    int n, k;
    cin >> n >> k;
    int ans = n;
    vector<int> v(n);
    multiset<int> ms;
    for (auto &vl : v)
    {
        cin >> vl;
        ms.insert((-1) * vl);
    }
    // for (auto vl : ms)
    //     cerr << vl << " ";
    for (auto vl : v)
    {
        int rem = k - vl;
        rem *= (-1);
        if (ms.find((-1) * vl) != ms.end())
            ms.erase(ms.find((-1) * vl));
        else
            continue;
        auto it = lower_bound(all(ms), rem);
        if (it == ms.end())
            continue;
        ms.erase(it);
        ans--;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}