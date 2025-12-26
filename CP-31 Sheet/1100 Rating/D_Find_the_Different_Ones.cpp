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
    vector<int> v(n), neo(n + 1, 0);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
        {
            neo[i] = i + 1;
        }
        else
            neo[i] = neo[i - 1];
        // cerr << neo[i] << " ";
    }
    for (auto vl : neo)
        cerr << vl << " ";
    cerr << endl;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (neo[r - 1] == neo[l - 1])
            cout << -1 << " " << -1 << endl;
        else
            cout << neo[r - 1] << " " << neo[r - 1] - 1 << endl;
    }
    cout << endl;
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