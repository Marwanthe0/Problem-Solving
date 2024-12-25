#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    vector<int> v(n - 1);
    for (auto &vl : v)
        cin >> vl;
    vector<int> ans;
    ans.push_back(v[0]);
    for (ll i = 1; i < n - 1; i++)
    {
        ans.push_back(v[i] | v[i - 1]);
    }
    ans.push_back(v.back());
    for (ll i = 1; i < n; i++)
    {
        if ((ans[i] & ans[i - 1]) != v[i - 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    for (auto &vl : ans)
        cout << vl << " ";
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