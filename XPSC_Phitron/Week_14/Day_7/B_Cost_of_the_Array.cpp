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
    if (n == k)
    {
        vector<int> t;
        for (int i = 1; i < n; i += 2)
        {
            t.push_back(v[i]);
        }
        int count = 1;
        for (auto vl : t)
        {
            if (vl != count)
            {
                cout << count << endl;
                return;
            }
            else
                count++;
        }
        cout << count << endl;
    }
    else
    {
        for (int i = 1; i < n - (k - 2); i++)
        {
            if (v[i] != 1)
            {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
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