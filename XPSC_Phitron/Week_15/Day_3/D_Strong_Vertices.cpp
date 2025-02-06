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
    vector<int> a(n), b(n), c;
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < n; i++)
    {
        c.push_back(a[i] - b[i]);
    }
    int mx = *max_element(all(c));
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == mx)
        {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
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