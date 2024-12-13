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
    map<ll, ll> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    vector<ll> xs;
    for (auto vl : m)
    {
        if (vl.second >= k)
        {
            xs.push_back(vl.first);
        }
    }
    if (xs.empty())
    {
        cout << -1 << endl;
        return;
    }
    ll first = xs[0], last, dif = LONG_LONG_MIN, ans1, ans2;
    for (ll i = 1; i < xs.size(); i++)
    {
        if (xs[i] - xs[i - 1] > 1)
        {
            last = xs[i - 1];
            if (last - first > dif)
            {
                dif = last - first;
                ans1 = first, ans2 = last;
                first = xs[i];
            }
        }
    }
    if (xs.back() - first > dif)
    {
        dif = xs.back() - first;
        ans2 = xs.back();
        ans1 = first;
    }
    cout << ans1 << " " << ans2 << endl;
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