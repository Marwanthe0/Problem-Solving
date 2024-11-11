#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> songs;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (b == y)
        {
            songs.push_back(a);
        }
    }
    sort(songs.begin(), songs.end(), greater<int>());
    if (songs.size() >= x)
    {
        ll ans = 0;
        for (ll i = 0; i < x; i++)
        {
            ans += songs[i];
        }
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
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