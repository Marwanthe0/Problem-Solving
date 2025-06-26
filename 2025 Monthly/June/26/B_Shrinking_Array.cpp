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
    if (n == 2)
    {
        if (abs(v[0] - v[1]) > 1)
        {
            cout << -1 << endl;
        }
        else
            cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(v[i] - v[i + 1]) <= 1)
        {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        int a = v[i], b = v[i + 1], c = v[i + 2];
        int x = max(b, c), y = min(b, c);
        x++, y--;
        if (a >= y && a <= x)
        {
            cout << 1 << endl;
            cerr << a << " " << x << " " << y << endl;
            return;
        }
    }
    for (int i = n - 1; i > 1; i--)
    {
        int a = v[i], b = v[i - 1], c = v[i - 2];
        int x = max(b, c), y = min(b, c);
        x++, y--;
        if (a >= y && a <= x)
        {
            cout << 1 << endl;
            cerr << a << " " << x << " " << y << endl;
            return;
        }
    }
    cout << -1 << endl;
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