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
int points(vector<int> v, int x, int k)
{
    int points = 0;
    for (auto vl : v)
    {
        if (abs(x - vl) < abs(k - vl))
            points++;
    }
    return points;
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (points(v, k - 1, k) > points(v, k + 1, k))
        cout << k - 1 << endl;
    else
        cout << k + 1 << endl;
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