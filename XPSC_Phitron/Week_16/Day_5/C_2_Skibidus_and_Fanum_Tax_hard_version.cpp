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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    sort(all(b));
    int last = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(all(b), a[i] + last);
        if (i && a[i] < a[i - 1])
        {
            no;
            return;
        }
        if (it == b.end())
        {
            last = a[i];
            continue;
        }
        int x = *it;
        a[i] = min(x - a[i], a[i]);
        last = a[i];
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