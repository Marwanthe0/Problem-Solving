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
    int x = 0;
    vector<int> ans(n, 0);
    vector<pair<int, int>> pp;
    for (int i = 0; i < n; i++)
    {
        pp.push_back({v[i], i});
    }
    sort(all(pp), greater<pair<int, int>>());
    int plus = 1, count = 0;
    for (auto [x, y] : pp)
    {
        // cerr << y << ":" << plus << endl;
        // ;
        if (count & 1)
        {
            ans[y] = (-1) * plus;
            plus++;
        }
        else
            ans[y] = plus;
        count++;
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer += 2 * (abs(ans[i])) * v[i];
    }
    cout << answer << endl;
    // cerr << endl;
    cout << x << " ";
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