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
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
void marwan()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
        a[i].first = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].second;
        b[i].first = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].second;
        c[i].first = i;
    }
    sort(all(a), cmp);
    sort(all(b), cmp);
    sort(all(c), cmp);
    // for (auto vl : a)
    //     cout << vl.second << " ";
    // cout << endl;
    // for (auto vl : b)
    //     cout << vl.second << " ";
    // cout << endl;
    // for (auto vl : c)
    //     cout << vl.second << " ";
    // cout << endl;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (a[i].first == b[j].first || a[i].first == c[k].first || b[j].first == c[k].first)
                    continue;
                sum = max(sum, a[i].second + b[j].second + c[k].second);
                cerr << a[i].second << " " << b[j].second << " " << c[k].second << endl;
            }
        }
    }
    cerr << endl;
    cout
        << sum << endl;
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