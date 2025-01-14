#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll calc(ll l, ll mid, ll r)
{
    ll pre = ((mid * (mid + 1)) / 2) - ((l * (l - 1)) / 2), post = ((r * (r + 1)) / 2) - ((mid * (mid + 1)) / 2);
    return abs(post - pre);
}
void marwan()
{
    ll n, k;
    cin >> n >> k;
    ll l = k, r = n + k, mid, ans, s = k, e = n + k - 1;

    while (l <= r)
    {
        mid = l + ((r - l) / 2);
        ll prev = calc(s, mid - 1, e);
        ll cur = calc(s, mid, e);
        ll next = calc(s, mid + 1, e);
        if (cur <= prev && cur <= next)
        {
            ans = cur;
            break;
        }
        else if (prev > cur && next < cur)
        {
            ans = next;
            l = mid + 1;
        }
        else
        {
            ans = prev;
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}