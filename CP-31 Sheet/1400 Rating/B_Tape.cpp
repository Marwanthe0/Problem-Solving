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
    int n, a, k;
    cin >> n >> a >> k;
    vector<int> v(n), dif;
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i < n; i++)
    {
        dif.push_back(v[i] - v[i - 1] - 1);
        // cerr << dif.back() << " ";
    }
    sort(all(dif));
    int ans = n;
    for (int i = 0; i < n - k; i++)
    {
        ans += dif[i];
    }
    cout << ans << endl;
    // cerr << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}