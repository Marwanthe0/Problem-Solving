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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    set<int> ms;
    int ans = 0, idx = 0;
    for (int i = 0; i < k; i++)
    {
        // idx = min(n - 1, idx);
        if (idx >= n)
        {
            ans += *(--ms.end());
            cerr << *(--ms.end()) << " ";
            continue;
        }
        if (ms.empty() || *(--ms.end()) <= v[idx].first || ((k - i) * (*(--ms.end())) < (v[idx].first + ((k - i - 1) * (v[idx].second)))))
            {
                ans += v[idx].first;
                cerr << (v[idx].first) << " ";
                ms.insert(v[idx].second);
                idx++;
            }
        else
        {
            ans += *(--ms.end());
            cerr << *(--ms.end()) << " ";
            // ms.insert(v[idx].second);
            // idx++;
        }
    }
    cerr << endl;
    cout << ans << endl;
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