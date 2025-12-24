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
    vector<int> v(n + 1);
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        m[v[i]] = i;
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int tg = ((2 * i) - 1) / v[i];
        for (auto [x, y] : m)
        {
            if (x > tg)
                break;
            else if (y + i == (x * v[i]))
                count++;
        }
    }
    cout << count << endl;
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