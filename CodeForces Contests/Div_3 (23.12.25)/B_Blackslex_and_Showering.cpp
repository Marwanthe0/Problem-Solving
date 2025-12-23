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
    int n, mx = INT_MIN, mxidx = 0;
    cin >> n;
    vector<int> v(n), a;
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < n; i++)
    {
        int dif = 0;
        if (i == 0)
            dif += abs(v[i + 1] - v[i]);
        else if (i == n - 1)
            dif += abs(v[i] - v[i - 1]);
        else
        {
            if ((v[i] > v[i - 1] && v[i] > v[i + 1]) || (v[i] < v[i - 1] && v[i] < v[i + 1]))
                dif = abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]) - abs(v[i + 1] - v[i - 1]);
        }
        if (dif > mx)
        {
            mx = dif, mxidx = i;
        }
    }
    for (int i = 0; i < n; i++)
        if (i != mxidx)
            a.push_back(v[i]);
    int sum = 0;
    for (int i = 1; i < n - 1; i++)
        sum += abs(a[i] - a[i - 1]);
    cout << sum << endl;
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