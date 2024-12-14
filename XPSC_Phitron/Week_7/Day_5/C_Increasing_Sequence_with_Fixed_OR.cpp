#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> ans;
    ans.push_back(n);
    for (ll i = 0; i <= __lg(n); i++)
    {
        if ((n >> i) & 1)
        {
            ans.push_back(n - (1LL << i));
        }
    }
    if ((n & (n - 1)) == 0)
        ans.pop_back();
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto vl : ans)
        cout
            << vl << " ";
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