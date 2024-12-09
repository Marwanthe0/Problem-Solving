#include <bits/stdc++.h>
using namespace std;
#define ll long long

void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;

    unordered_map<ll, vector<ll>> m;
    for (ll i = 0; i < n; i++)
    {
        m[v[i]].push_back(i);
    }
    if (m.size() == 1)
    {
        cout << m.begin()->first << " " << 0 << endl;
        return;
    }

    ll mnd = LLONG_MAX, bst = LONG_LONG_MAX;
    for (const auto &vl : m)
    {
        ll cln = vl.first;
        const vector<ll> &pos = vl.second;

        ll mxg = 0;
        for (ll i = 1; i < pos.size(); i++)
        {
            ll gap = pos[i] - pos[i - 1];
            mxg = max(mxg, (gap) / 2);
        }
        mxg = max(mxg, pos[0]);
        mxg = max(mxg, n - 1 - pos.back());
        if (mxg < mnd || (mxg == mnd && cln < bst))
        {
            mnd = mxg;
            bst = cln;
        }
    }

    cout << bst << " " << mnd << endl;
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
