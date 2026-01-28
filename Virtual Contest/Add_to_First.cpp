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
    vector<int> a(n), b(n), pf(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < n; i++)
        pf[i] = (i ? max(pf[i - 1], a[i]) : a[i]);
    // for (auto vl : pf)
    //     cerr << vl << " ";
    for (int i = n - 1; i >= 1; i--)
    {
        // cerr << pf[i] << " ";
        if (a[i] != b[i])
        {
            if (b[i] < a[i] || pf[i - 1] >= a[i])
            {
                no;
                return;
            }
        }
    }
    if (a[0] > b[0])
    {
        no;
        return;
    }
    // cerr << endl;
    yes;
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