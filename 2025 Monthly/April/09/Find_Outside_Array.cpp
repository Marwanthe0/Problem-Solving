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
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    int mx = *max_element(all(v));
    if (mx == *min_element(all(v)) && mx == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto vl : v)
        {
            if (m.find(2 * vl) == m.end())
            {
                cout << vl << " " << vl << endl;
                return;
            }
        }
    }
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