#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
        // cout << v[i] << " ";
    }
    // cout << endl;
    string s;
    cin >> s;
    s = '0' + s;
    ll l = 1, r = n;
    ll ans = 0;
    while (l < r)
    {
        if (s[l] == 'L' && s[r] == 'R')
        {
            ans += (v[r] - v[l - 1]);
            l++, r--;
        }
        if (s[l] != 'L')
            l++;
        if (s[r] != 'R')
            r--;
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