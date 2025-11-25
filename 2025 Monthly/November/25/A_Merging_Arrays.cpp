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
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int l = 0, r = 0;
    while (l < n && r < m)
    {
        if (a[l] < b[r])
        {
            cout << a[l++] << " ";
        }
        else
            cout << b[r++] << " ";
    }
    while (l < n)
        cout << a[l++] << " ";
    while (r < m)
        cout << b[r++] << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}