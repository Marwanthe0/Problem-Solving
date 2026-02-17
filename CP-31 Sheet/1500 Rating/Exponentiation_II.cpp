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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int mod(int x, int m = M) { return x % M; }
int binexp(int base, int exp)
{
    int res = 1ll;
    while (exp)
    {
        if (exp & 1)
            res = mod(res * 1ll * base);
        base = mod(base * 1ll * base);
        exp >>= 1;
    }
    return mod(res);
}
void marwan()
{
    int a, b, c;
    cin >> a >> b >> c;
    // int d = binexp(b, c);
    cout << binexp(a, binexp(b, c)) << endl;
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