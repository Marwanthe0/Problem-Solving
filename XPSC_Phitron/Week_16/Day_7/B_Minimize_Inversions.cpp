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
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.first == b.first)
        return a.second.first < b.second.first;
    return a.first < b.first;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, pair<int, int>>> s(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < n; i++)
    {
        s[i].first = a[i] + b[i];
        s[i].second.first = a[i];
        s[i].second.second = b[i];
    }
    sort(all(s), cmp);
    for (auto vl : s)
        cout << vl.second.first << " ";
    cout << endl;
    for (auto vl : s)
        cout << vl.second.second << " ";
    cout << endl;
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