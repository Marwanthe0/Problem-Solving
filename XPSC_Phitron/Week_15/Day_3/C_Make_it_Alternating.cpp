#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s;
    cin >> s;
    int n = s.size(), k = s.size(), ans = 1;
    for (int l = 0; l < n;)
    {
        int r = l + 1;
        while (r < n && s[l] == s[r])
            ++r;
        int x = ans * (1.0) * (r - l);
        ans = x % M;
        --k;
        l = r;
    }
    for (int i = 1; i <= k; i++)
    {
        int x = (ans * (1.0) * i);
        ans = x % M;
    }
    cout << k << " " << ans << endl;
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