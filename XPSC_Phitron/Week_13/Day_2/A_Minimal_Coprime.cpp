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
void marwan()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n + 1, 0ll), w, pre, post;
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    for (ll i = l; i <= r; i++)
        w.push_back(v[i]);
    // for (auto vl : w)
    //     cout << vl << " ";
    sort(all(w));
    for (ll i = 1ll; i < l; i++)
    {
        pre.push_back(v[i]);
    }
    for (ll i = r + 1ll; i <= n; i++)
        post.push_back(v[i]);
    vector<ll> temp = w;
    sort(all(pre));
    sort(all(post));
    cerr << "pre\n";
    for (auto vl : pre)
        cerr << vl << " ";
    cerr << endl;
    cerr << "post\n";
    for (auto vl : post)
        cerr << vl << " ";
    cerr << endl;
    ll sum = 0, ans = LONG_LONG_MAX;
    for (ll i = 1ll; i < l; i++)
    {
        if (temp.empty() || temp.back() <= pre[i - 1ll])
            break;
        sum += pre[i - 1ll];
        temp.pop_back();
    }
    sum += accumulate(all(temp), 0ll);
    ans = min((ll)ans, (ll)sum);
    sum = 0ll;
    temp = w;
    cerr << "err\n";
    for (ll i = r + 1ll; i <= n; i++)
    {
        if (temp.empty() || temp.back() <= post[i - (r + 1ll)])
            break;
        sum += post[i - (r + 1ll)];
        cerr << post[i - (r + 1ll)] << " ";
        temp.pop_back();
    }
    sum += accumulate(all(temp), 0ll);
    cerr << sum << endl;
    ans = min((ll)ans, (ll)sum);
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