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
    int ans = INT_MAX, last = 0;
    for (int i = 0; i < n - 1; i++)
    {
        last = i;
        while ((i < n - 1) && v[i] == v[i + 1])
            i++;
        ans = min(ans, (v[last] * last) + ((n - i - 1) * v[last]));
    }
    int x = n, ls = n - 1;
    while (ls >= 0 && v[ls] == v.back())
        ls--, x--;
    ans = min(ans, v.back() * x);
    cout
        << ans << endl;
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