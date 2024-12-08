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
    vector<vector<ll>> x;
    for (ll i = 0; i < n; i++)
    {
        vector<ll> temp;
        temp.push_back(i + 1);
        for (ll j = 0; j < n; j++)
        {
            if (i != j)
            {
                temp.push_back(abs(v[i] - v[j]));
            }
        }
        x.push_back(temp);
    }
    for (auto vc : x)
    {
        bool flag = true;
        for (ll j = 1; j < vc.size(); j++)
        {
            if (vc[j] % k == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            yes;
            cout << vc[0] << endl;
            return;
        }
    }
    no;
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