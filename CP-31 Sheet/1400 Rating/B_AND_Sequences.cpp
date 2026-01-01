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
int fact(int n)
{
    if (n == 0ll)
        return 1ll;
    return (n * (fact(n - 1ll)) % M);
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int x = (~0);
    for (auto &vl : v)
    {
        cin >> vl;
        x &= vl;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
            count++;
    }
    // cerr << count << endl;
    int ans = (count * (count - 1));
    ans = ((ans % M * (fact(n - 2) % M)) % M);
    cout << ans << endl;
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