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
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    int low = k * b, upper = low + (n * (k - 1));
    if (s >= low && s <= upper)
    {
        vector<int> v = {min(s, low + (k - 1))};
        s -= min(s, low + (k - 1));
        int x = n - 1;
        while (s > 0)
        {
            v.push_back(min(s, k - 1));
            s -= (k - 1);
            x--;
            if (x < 0)
            {
                cout << -1 << endl;
                return;
            }
        }
        while (x--)
            v.push_back(0);
        for (auto vl : v)
            cout << vl << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
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