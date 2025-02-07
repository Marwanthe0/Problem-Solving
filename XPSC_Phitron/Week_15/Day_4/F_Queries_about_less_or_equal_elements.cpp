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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), q(k);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    for (auto &vl : q)
    {
        cin >> vl;
        cout << upper_bound(all(v), vl) - v.begin() << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}