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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
    {
        int x;
        cin >> x;
        vl = x;
    }
    sort(all(b), greater<int>());
    vector<int> ans;
    if (b.front() >= a[n - 1ll] + a[n - 2ll])
        a[n - 1ll] = b.front() - a[n - 1ll];
    for (int i = n - 1ll; i >= 0ll; i--)
    {
        if (a[i] <= a[i + 1ll])
        {
            continue;
        }
        else
        {
            int s = a[i] + a[i + 1ll];
            if (b.back() - a[i] > a[i + 1])
            {
                no;
                return;
            }
            auto it = upper_bound(all(b), s, greater<int>());
            if (it == b.end())
            {
                no;
                return;
            }
            a[i] = ((*it))-a[i];
            if (a[i] > a[i + 1ll])
            {
                no;
                return;
            }
        }
    }
    yes;
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