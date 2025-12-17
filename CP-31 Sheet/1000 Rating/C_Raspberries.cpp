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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    map<int, int> m;
    for (auto &vl : v)
    {
        vl = (vl % k);
        if (vl == 0)
        {
            cout << 0 << endl;
            return;
        }
        else
            vl = k - vl;
        m[vl]++;
    }
    // cerr << k << endl;
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    if (k == 4)
    {
        if (m[2] > 1)
            cout << 0 << endl;
        else if ((m[2] > 0 && m[3] > 0) || m[1] > 0)
            cout << 1 << endl;
        else if (m[1])
            cout << 1 << endl;
        else if (m[3] > 1)
            cout << 2 << endl;
        else
            cout << *min_element(all(v)) << endl;
        return;
    }
    cout << *min_element(all(v)) << endl;
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