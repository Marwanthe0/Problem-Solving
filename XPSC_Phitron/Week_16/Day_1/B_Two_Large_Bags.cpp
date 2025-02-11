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
    vector<int> v(n);
    map<int, int> m, x;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
        int temp = vl;
        while (m[temp] > 2)
        {
            m[temp]--;
            m[++temp]++;
        }
    }
    for (auto vl : m)
    {
        if (vl.second & 1)
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