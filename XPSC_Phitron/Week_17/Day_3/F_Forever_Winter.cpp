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
    int n, e;
    cin >> n >> e;
    map<int, int> m;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        m[a]++, m[b]++;
    }
    int count = 0;
    for (auto vl : m)
    {
        if (vl.second == 1)
            count++;
    }
    // cout << count << endl;
    int x = n - count - 1;
    cout << x << " " << count / x << endl;
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