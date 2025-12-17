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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (auto &vl : v)
        cin >> vl.first;
    for (auto &vl : v)
        cin >> vl.second;
    sort(all(v), cmp);
    int count = k;
    int rem = n - 1;
    // for (auto vl : v)
    //     cerr << vl.first << " " << vl.second << endl;
    // cerr << endl;
    for (int i = 0; i < n; i++)
    {
        if (rem <= 0)
            break;
        if (v[i].second > k)
        {
            count += rem * k;
            break;
        }
        if (v[i].first <= rem)
        {
            count += v[i].first * v[i].second;
            rem -= v[i].first;
        }
        else
        {
            count += v[i].second * rem;
            rem = 0;
        }
        if (rem <= 0)
            break;
    }
    cout << count << endl;
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