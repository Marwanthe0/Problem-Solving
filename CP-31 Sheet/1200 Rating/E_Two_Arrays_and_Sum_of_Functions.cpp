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

    int n;
    cin >> n;
    vector<__int128> a(n);
    vector<int> b(n);
    for (int i = 0ll; i < n; i++)
    {
        int x;
        cin >> x;
        // a[i] = (((int)a[i]) * ((int)((i + 1ll) * (n - i))));
        a[i] = (__int128)((x) * (i + 1) * (n - i));
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(all(b), greater<int>());
    sort(all(a));
    int ans = 0ll;
    for (int i = 0ll; i < n; i++)
    {
        ans = (ans + (long long)((b[i] % M) * (a[i] % M))) % M;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}