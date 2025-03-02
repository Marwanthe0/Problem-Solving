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
    a[0] = m;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(all(a)), sort(all(b));
    for (auto vl : a)
        cerr << vl << " ";
    cerr << endl;
    for (auto vl : b)
        cerr << vl << " ";
    cerr << endl;
    auto tt = b.begin();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(tt, b.end(), a[i]);
        if (it == b.end())
        {
            cerr << endl;
            cout << n - count << endl;
            return;
        }
        else
        {
            count++;
            tt = it;
            cerr << tt - b.begin() << " ";
            tt++;
        }
    }
    cerr << endl;
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