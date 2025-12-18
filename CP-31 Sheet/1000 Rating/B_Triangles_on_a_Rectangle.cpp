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
    int w, h;
    cin >> w >> h;
    int a;
    cin >> a;
    vector<int> av(a);
    for (auto &vl : av)
        cin >> vl;
    int b;
    cin >> b;
    vector<int> bv(b);
    for (auto &vl : bv)
        cin >> vl;
    int c;
    cin >> c;
    vector<int> cv(c);
    for (auto &vl : cv)
        cin >> vl;
    int d;
    cin >> d;
    vector<int> dv(d);
    for (auto &vl : dv)
        cin >> vl;
    int mx = (av.back() - av.front()) * h;
    // cerr << mx << " ";
    mx = max(mx, (bv.back() - bv.front()) * h);
    // cerr << mx << " ";
    mx = max(mx, ((cv.back() - cv.front()) * w));
    // cerr << mx << " ";
    mx = max(mx, (dv.back() - dv.front()) * w);
    // cerr << mx << " ";
    // cerr << endl;
    cout << mx << endl;
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