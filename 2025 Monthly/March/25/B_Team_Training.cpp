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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v), greater<int>());
    int cnt = 0, count = 0, mx = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= x)
            count++;
        else
        {
            cnt++, mx = min(mx, v[i]);
            if (cnt * mx >= x)
                count++, cnt = 0;
        }
    }
    cout << count << endl;
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