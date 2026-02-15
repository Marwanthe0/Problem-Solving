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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (n == 2)
    {
        cout << v[1] << " " << v[0] << endl;
        return;
    }
    vector<int> ans(n, 0);
    for (int i = 0; i + 2 < n; i++)
    {
        ans[i + 1] = (v[i] + v[i + 2] - (2 * v[i + 1])) / 2;
    }
    int sum = 0, sum2 = 0;
    for (int i = 1; i < n - 1; i++)
        sum += (i * ans[i]);
    ans.back() = (v[0] - sum) / (n - 1);
    for (int i = 2; i < n; i++)
    {
        sum2 += (i - 1) * ans[i];
    }
    ans.front() = (v[1] - sum2);
    for (auto vl : ans)
        cout
            << vl << " ";
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