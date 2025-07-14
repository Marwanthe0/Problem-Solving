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
    vector<int> v(n), a;
    for (auto &vl : v)
        cin >> vl;
    a = v;
    sort(all(v));
    int x = 0, idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == a[i])
            x++, idx = i;
    }
    if (!x)
    {
        yes;
        cout << n << endl;
        for (auto vl : v)
            cout << vl << " ";
        cout << endl;
    }
    else if (x == 1)
    {
        yes;
        cout << n - 1 << endl;
        for (int i = 0; i < n; i++)
        {
            if (i != idx)
                cout << v[i] << " ";
        }
        cout << endl;
    }
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}