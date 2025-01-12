#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second - a.first > b.second - b.first; }
void marwan()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    sort(all(v), cmp);
    // for (auto &vl : v)
    //     cout << vl.first << " ";
    // cout << endl;
    // for (auto &vl : v)
    //     cout << vl.second << " ";
    if (v[0].first > v[0].second)
    {
        yes;
        return;
    }
    int count = v[0].second - v[0].first;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first - count < v[i].second)
        {
            no;
            return;
        }
    }
    yes;
}
int main()
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