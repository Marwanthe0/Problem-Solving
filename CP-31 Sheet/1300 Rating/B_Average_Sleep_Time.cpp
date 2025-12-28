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
    int w = ((n - k) + 1);
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = 0;
    for (int i = 1; i <= (n / 2); i++)
    {
        ans += ((v[i - 1] + v[n - i]) * (min(i, min(w, k))));
    }
    if (n & 1)
    {
        ans += min(w, k) * (v[(n / 2)]);
    }
    cout << fixed << setprecision(10) << (ans / ((1.0) * w)) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}