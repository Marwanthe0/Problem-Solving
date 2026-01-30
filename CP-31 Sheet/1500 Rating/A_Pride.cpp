#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (n == 1)
    {
        if (v[0] == 1)
            cout << 0 << endl;
        else
            cout << -1 << endl;
        return;
    }
    int c1 = 0;
    for (auto vl : v)
        if (vl == 1)
            c1++;
    for (int i = 1; i < n; i++)
    {
        if (__gcd(v[i], v[i - 1]) == 1)
        {
            cout << n - c1 << endl;
            return;
        }
    }
    bool flag = true;
    int x = v[0];
    for (int i = 0; i < n; i++)
    {
        x = __gcd(x, v[i]);
    }
    if (x != 1)
    {
        cout << -1 << endl;
        return;
    }
    int mn = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int x = v[i];
        for (int j = i + 1; j < n; j++)
        {
            x = __gcd(v[j], x);
            if (x == 1)
            {
                mn = min(mn, j - i + 1);
            }
        }
    }
    cout << (mn - 1) + (n - 1) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}