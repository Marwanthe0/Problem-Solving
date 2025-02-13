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
    vector<int> v(n);
    int dif = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i)
            dif = max(dif, v[i] - v[i - 1]);
    }
    dif = max({dif, v.front(), 2 * (k - v.back())});
    cout << dif << endl;
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