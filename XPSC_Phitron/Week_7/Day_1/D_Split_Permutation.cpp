#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll x, n;
    cin >> x;
    n = (x / 2) * 2;
    ll l = 1,
        r = n;
    vector<ll> ans;
    while (l <= r)
    {
        ans.push_back(l);
        if (l != r)
            ans.push_back(r);
        l++,
            r--;
    }
    if (x % 2)
        ans.push_back(x);
    for (auto vl : ans)
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