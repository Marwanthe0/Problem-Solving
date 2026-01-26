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
    int add = 0ll, cnt = 0ll, ans = 0ll;
    for (int i = 1; i < n; i++)
    {
        if (v[i]< v[i - 1])
        {
            while (v[i] + ((1ll << cnt) - 1ll) < v[i - 1])
            {
                cnt++;
            }
            v[i] = v[i - 1];
        }
    }
    cout << cnt << endl;
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