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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int l = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[l % m])
        {
            mp[i]++, l++;
        }
    }
    if (l >= 2 * m)
        yes;
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}