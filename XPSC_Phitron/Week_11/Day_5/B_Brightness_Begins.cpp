#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll k, l = 1, r = 2e18;
    cin >> k;
    while (r - l > 1)
    {
        ll mid = (l + r) >> 1;
        ll n = mid - int(sqrtl(mid));
        if (n >= k)
            r = mid;
        else
            l = mid;
    }
    cout << r << "\n";
}
int main()
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