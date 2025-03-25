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
    map<int, int> m = {{0, 3}, {2, 2}, {1, 1}, {3, 1}, {5, 1}};
    for (int i = 0; i < n; i++)
    {
        m[v[i]]--;
        bool flag = true;
        for (auto vl : m)
        {
            if (vl.second > 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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