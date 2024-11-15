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
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll count = 0;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    map<int, int> m;
    int mx = INT_MIN, ans = 0, idx = 0, flag = 1;
    for (auto vl : v)
    {
        m[vl]++;
        if (m[vl] > 1)
            flag = 0;
        if (m[vl] > mx)
        {
            mx = m[vl];
            ans = vl;
        }
    }
    if (flag)
    {
        cout << n - 1 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (ans == v[i])
        {
            idx = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == idx || v[i] == ans)
            continue;
        else if (i < idx && v[i] > ans)
            count++;
        else if (i > idx && v[i] < ans)
            count++;
    }
    cout << count << endl;
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