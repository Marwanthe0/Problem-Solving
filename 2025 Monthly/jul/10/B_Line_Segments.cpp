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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int sum = accumulate(all(v), 0ll);
    double dis = sqrt((pow(abs(c - a), 2) + pow(abs(d - b), 2)));
    cerr << dis << endl;
    sort(all(v));
    int ans = 0;
    reverse(all(v));
    for (int i = 0; i < n; i++)
    {
        int a1 = ans - v[i], a2 = ans + v[i];
        
    }
    ans = abs(ans);
    cerr << "ans" << ans << endl;
    if (dis >= ans && dis <= sum)
        yes;
    else
        no;
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