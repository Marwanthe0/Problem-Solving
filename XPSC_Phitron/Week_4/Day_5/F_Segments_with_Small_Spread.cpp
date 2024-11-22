#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    multiset<ll> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll l = 0, r = 0, ans = 0;
    while (l < n && r < n)
    {
        s.insert(v[r]);
        ll mx = *(--s.end()), mn = *s.begin();
        if (mx - mn <= k)
        { 
            ans += r - l + 1;
        }
        else
        {
            while ((*(--s.end()) - *s.begin() > k) && l < r)
                s.erase(s.find(v[l++]));
            ll mx = *(--s.end()), mn = *s.begin();
            if (mx - mn <= k)
                ans += r - l + 1;
        }
        r++;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}