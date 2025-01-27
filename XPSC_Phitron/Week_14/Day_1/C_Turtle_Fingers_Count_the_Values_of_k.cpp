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
bool pos(int a, int b, int n)
{
    int x = 1, y = 1;
    while (x < n)
    {
        x *= a;
        if (x == n)
            return true;
    }
    while (y < n)
    {
        y *= b;
        if (y == n)
            return true;
    }
    x = 1, y = 1;
    while (y < n)
    {
        y *= b;
        x = y;
        while (x < n)
        {
            x *= a;
            if (x == n)
                return true;
        }
    }
    x = 1, y = 1;
    while (x < n)
    {
        x *= a;
        y = x;
        while (y < n)
        {
            y *= b;
            if (y == n)
                return true;
            true;
        }
    }
    return false;
}
void marwan()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> div;
    for (int i = 1; i * i <= c; i++)
    {
        if (c % i == 0)
        {
            div.push_back(i);
            if (c / i != i)
                div.push_back(c / i);
        }
    }
    sort(all(div));
    int ans = 0;
    for (auto vl : div)
    {
        if (pos(a, b, (c / vl)))
            ans++;
    }
    cout << ans + 1 << endl;
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