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
    vector<string> v(3);
    for (int i = 0; i < 3; i++)
        cin >> v[i];
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        if (v[1][i] != v[2][i])
        {
            if (v[1][i] == '0')
            {
                a.push_back(i);
            }
            else
                b.push_back(i);
        }
    }
    if (a.empty() && b.empty())
    {
        cout << 0 << endl;
        // cerr << endl;
        return;
    }
    int ans = max(a.size(), b.size());
    vector<int> aa(2, 0), bb(2, 0);
    for (auto vl : a)
    {
        if (v[0][vl] == '0')
        {
            aa[0]++;
        }
        else
            aa[1]++;
    }
    for (auto vl : b)
    {
        if (v[0][vl] == '0')
        {
            bb[0]++;
        }
        else
            bb[1]++;
    }
    // for (auto vl : a)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : b)
    //     cerr << vl << " ";
    // cerr << endl;
    for (int i = 0; i < 2; i++)
    {
        ans -= min(aa[i], bb[i]);
        // cerr << aa[i] << " " << bb[i] << endl;
    }
    cout << ans << endl;
    // cerr << endl;
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