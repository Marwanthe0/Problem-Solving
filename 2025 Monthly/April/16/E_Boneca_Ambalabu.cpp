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
    vector<int> a(n);
    int mx = 0;
    for (auto &vl : a)
    {
        cin >> vl;
        mx = max(mx, __lg(vl));
    }
    vector<int> v;
    for (int i = 0; i <= mx; i++)
    {
        int count = 0;
        for (auto vl : a)
        {
            count += ((vl >> i) & 1);
        }
        v.push_back(count);
    }
    int ans = 0, k = 1;
    // reverse(all(v));
    for (auto vl : v)
        cerr << vl << " ";
    cerr << endl;
    for (auto vl : a)
    {
        int count = 0, k = 1;
        // cout << vl << endl;
        for (int i = 0; i < v.size(); i++)
        {
            if (((vl >> i) & 1))
                count += (k * (n - v[i]));
            else
                count += (k * v[i]);
            // cout << count << " ";
            k *= 2;
        }
        // cout << endl;
        cerr << count << " ";
        ans = max(ans, count);
    }
    // cout << endl;
    cerr
        << endl;
    cout << ans << endl;
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