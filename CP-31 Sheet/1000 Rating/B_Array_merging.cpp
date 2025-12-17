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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int count1 = 0, count2 = 0;
    map<int, int> m, p;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while (i < n && x == a[i])
        {
            count1++, i++;
        }
        --i;
        m[a[i]] = max(m[a[i]], count1);
        count1 = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x = b[i];
        while (i < n && x == b[i])
        {
            count2++, i++;
        }
        --i;
        p[b[i]] = max(p[b[i]], count2);
        count2 = 0;
    }
    for (auto [x, y] : m)
    {
        p[x] += y;
        // cerr << x << " " << y << endl;
    }
    // cerr << endl;
    // for (auto [x, y] : p)
    // {
    //     // p[x] += y;
    //     cerr << x << " " << y << endl;
    // }
    // cerr << endl;
    int ans = 0;
    for (auto [x, y] : p)
        ans = max(ans, y);
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