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
    vector<int> v(3);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    if (v.back() - v.front() >= 10)
        cout << "check again" << endl;
    else
        cout << "final " << v[1] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}