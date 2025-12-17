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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int mx = a[0], mxidx = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if ((b[i + 1] + a[i]) > mx)
        {
            mx = (b[i + 1] + a[i]);
            mxidx = i;
        }
    }
    if (a[0] - b[0] > m)
    {
        cout << m * a[0] << endl;
        return;
    }
    int count = 0, bsum = 0;
    for (int i = 0; i <= mxidx; i++)
        bsum += b[i];
    int tt = (a[mxidx] - bsum);
    count += (a[mxidx] - bsum) * mx;
    // cerr << tt << " " << mx << " " << mxidx << " " << bsum << endl;
    int dt = ((mx + 1) + (m - (a[mxidx] - bsum)));
    dt = (dt * (dt - 1)) / 2;
    count += (dt - (mx * (mx + 1)) / 2);
    cout
        << count << endl;
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