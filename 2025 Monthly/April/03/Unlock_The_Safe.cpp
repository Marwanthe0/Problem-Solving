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
int dis(int a, int b)
{
    int dif = abs(a - b), dif2 = (9 - max(a, b)) + min(a, b);
    return min(dif, dif2);
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int op = 0;
    for (int i = 0; i < n; i++)
    {
        cerr << dis(a[i], b[i]) << " ";
        k -= dis(a[i], b[i]);
        op += max(op, dis(a[i], b[i]));
        if (k <= 0)
        {
            no;
            return;
        }
    }
    cerr << endl;
    if (k % 2 == 0)
    {
        yes;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int d = dis(a[i], b[i]);
            if (k == 9 - 2 * d)
            {
                yes;
                return;
            }
        }
        no;
    }
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