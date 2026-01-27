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
    int count = 0;
    map<long double, int> m;
    for (int i = 0; i < n; i++)
    {
        if (!a[i])
        {
            if (b[i] == 0)
                count++;
            continue;
        }
        m[(long double)b[i] / (long double)a[i]]++;
    }
    int mx = 0;
    for (auto [x, y] : m)
        mx = max(mx, y);
    cout << count + mx << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}