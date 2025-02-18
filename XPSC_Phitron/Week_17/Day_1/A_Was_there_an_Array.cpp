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
    n -= 2;
    vector<int> v(n), o;
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < n; i++)
    {
        if (v[i])
            o.push_back(i);
    }
    for (int i = 1; i < o.size(); i++)
        if (o[i] - o[i - 1] == 2)
        {
            no;
            return;
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