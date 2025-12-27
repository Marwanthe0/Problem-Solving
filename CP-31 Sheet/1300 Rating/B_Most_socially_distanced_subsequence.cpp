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
    vector<int> ans = {v.front()};
    bool flag = (v[1] - v[0] > 0);
    for (int i = 1; i < n; i++)
    {
        if (v[i] - v[i - 1] > 0 != flag)
        {
            flag = (v[i] - v[i - 1]) > 0;
            ans.push_back(v[i - 1]);
        }
    }
    ans.push_back(v.back());
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