#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s;
    cin >> s;
    map<string, ll> m;
    for (ll i = 0; i < s.size(); i++)
    {
        string x;
        for (ll j = i; j < s.size(); j++)
        {
            x.push_back(s[j]);
            m[x]++;
        }
    }
    ll mx = LONG_LONG_MIN;
    for (auto vl : m)
    {
        // cout << vl.first << " " << vl.second << endl;
        if (vl.second >= 2)
        {
            // cout << vl.first.size() << endl;
            mx = max((ll)vl.first.size(), mx);
        }
    }
    if (mx != LONG_LONG_MIN)
        cout << mx << endl;
    else
        cout << 0 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}