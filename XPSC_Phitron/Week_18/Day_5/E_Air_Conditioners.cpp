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
    vector<int> a(k), b(k);
    map<int, int> m;
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < k; i++)
    {
        m[a[i]] = b[i];
    }
    // for (auto vl : m)
    //     cerr << vl.first << " " << vl.second << endl;
    // cerr << endl;
    vector<int> pre(n + 1), post(n + 1);
    for (int i = 0; i <= n; i++)
    {
        pre[i] = INT_MAX, post[i] = INT_MAX;
    }
    int last = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (m.find(i) != m.end())
        {
            last = min(last, m[i]);
        }
        pre[i] = last;
        if (last != INT_MAX)
            last++;
    }
    last = INT_MAX;
    for (int i = n; i >= 1; i--)
    {
        if (m.find(i) != m.end())
        {
            last = min(last, m[i]);
        }
        post[i] = last;
        if (last != INT_MAX)
            last++;
    }
    // for (auto vl : pre)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : post)
    //     cerr << vl << " ";
    // cerr << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << min(pre[i], post[i]) << " ";
    }
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