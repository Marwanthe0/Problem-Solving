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
    for (auto &vl : v)
        cin >> vl;
    int sum = accumulate(all(v), 0ll);
    if (sum & 1)
    {
        no;
        return;
    }
    sort(all(v));
    // for (int i = 1; i <= n; i++)
    //     v[i] += v[i - 1];
    for (int i = 0; i < n; i++)
    {
        if (2 * v[i] > sum)
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
    marwan();
    return 0;
}