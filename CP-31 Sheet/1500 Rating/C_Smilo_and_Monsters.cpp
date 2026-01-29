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
#define make_unique v.erase(unique(v.begin(), v.end()), v.end());
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    int sum = accumulate(all(v), 0ll), x = (sum / 2) + (sum % 2), y = sum / 2, r = n - 1, count = 0;
    while (y > 0)
    {
        y -= v[r--], count++;
    }
    cout << x + count << endl;
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