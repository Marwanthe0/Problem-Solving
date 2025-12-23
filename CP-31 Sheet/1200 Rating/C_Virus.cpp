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
    int n, m;
    cin >> n >> m;
    vector<int> v(m), a;
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    for (int i = 1; i < m; i++)
        a.push_back((v[i] - v[i - 1]) - 1);
    a.push_back(((n - v.back())) + (v[0] - 1));
    int pro = 0;
    sort(all(a), greater<int>());
    int x = 0;
    for (auto vl : a)
    {
        // cerr << vl << " ";
        if (x >= vl)
            break;
        pro++, x += 2;
        if (x >= vl)
            break;
        pro += max(0ll, (vl - x));
        x += 2;
    }
    // cerr << endl;
    cout << n - pro << endl;
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