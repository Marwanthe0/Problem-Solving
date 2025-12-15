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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    long double ans = (long double)v[0];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, (long double)(v[i] - v[i - 1]) / ((long double)2));
    }
    ans = max(ans, (long double)(k - v.back()));
    cout << fixed << setprecision(10) << ans << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}