#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll mex(set<ll> &s)
{
    ll idx = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it != idx)
        {
            return idx;
        }
        idx++;
    }
    return idx;
}
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    set<ll> s;
    for (auto vl : v)
        s.insert(vl);
    // for (ll i = 0; i < n; i++)
    // {
    //     ll x = mex(s);
    //     s.erase(v[i]);
    //     s.insert(x);
    //     v[i] = x;
    // }
    // for (auto vl : v)
    //     cout << vl << " ";
    // cout << endl;
    // k--;
    deque<ll> dq;
    for (auto vl : v)
        dq.push_back(vl);
    ll x = mex(s);
    deque<ll> dq2;
    if (k % (n + 1) == 0)
    {
        while (!dq.empty())
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
        return;
    }
    for (ll i = 0; i < (k % (n + 1)); i++)
    {
        dq2.push_front(dq.back());
        dq.pop_back();
    }
    dq.push_front(x);
    dq2.pop_front();
    while (!dq2.empty())
    {
        dq.push_front(dq2.back());
        dq2.pop_back();
    }
    // for (ll i = 0; i < (k % (n + 1)); i++)
    // {
    //     dq.push_back(dq.back());
    // }
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
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