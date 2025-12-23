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
    vector<int> v((n * (n - 1)) / 2), ans;
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    // for (auto vl : v)
    //     cout << vl << " ";
    int x = n - 1;
    for (int i = 0; i < v.size(); i += x, x--)
    {
        ans.push_back(v[i]);
    }
    if (ans.size() < n)
        ans.push_back(ans.back());
    for (auto vl : ans)
        cout << vl << " ";
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