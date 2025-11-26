#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    if (n == 1)
    {
        yes;
        return;
    }
    if ((a[1] >= min(a[0], b[0]) && a[1] <= max(a[0], b[0])) || (a[n - 2] >= min(a[n - 1], b[n - 1]) && a[n - 2] <= max(a[n - 1], b[n - 1])))
    {
        no;
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] == b[i])
            continue;
        int x = a[i + 1], y = a[i - 1];
        if ((x >= min(a[i], b[i]) && x <= max(a[i], b[i])) || (y >= min(a[i], b[i]) && y <= max(a[i], b[i])))
        {
            no;
            return;
        }
    }
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