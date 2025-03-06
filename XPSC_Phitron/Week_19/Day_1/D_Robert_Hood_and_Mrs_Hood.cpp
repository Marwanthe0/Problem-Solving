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
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(all(v));
    priority_queue<int, vector<int>, greater<int>> ms;
    int l = 0;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int j = i + d - 1;
        while (l < v.size() && v[l].first <= j)
        {
            ms.push(v[l].second);
            l++;
        }
        while (!ms.empty() && ms.top() < i)
            ms.pop();
        ans[i] = ms.size();
        // cout << ms.size() << " ";
    }
    int mx = INT_MIN, mn = INT_MAX, l1, l2;
    for (int i = 1; i <= n - d + 1; i++)
    {
        if (ans[i] > mx)
        {
            mx = ans[i];
            l1 = i;
        }
        if (ans[i] < mn)
        {
            mn = ans[i], l2 = i;
        }
        cerr << ans[i] << " ";
    }
    cerr << endl;
    cout << l1 << " " << l2 << endl;
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