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
    for (auto &vl : v)
        cin >> vl;
    map<ll, ll> m;
    ll l = 0, r = 0, ans = 0;
    while (l < n && r < n)
    {
        m[v[r]]++;
        // cerr << m.size() << " " << l << " " << r << " ::" << ans << endl;
        if (m.size() <= k)
        {
            ans += (r - l + 1);
        }
        else
        {
            while (l <= r && m.size() > k)
            {
                m[v[l]]--;
                if (m[v[l]] <= 0)
                    m.erase(v[l]);
                l++;
            }
            if (m.size() <= k)
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