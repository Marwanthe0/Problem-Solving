#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    ll l = 0, r = 0;
    ll ans = 0;
    while (l < n && r < m)
    {
        ll current = a[l], count1 = 0, count2 = 0;
        while (l < n && current == a[l])
            l++, count1++;
        while (r < m && current > b[r])
            r++;
        while (r < m && current == b[r])
            r++, count2++;
        ans += (1ll * count1 * count2);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}