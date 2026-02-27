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
    vector<int> v(n), a(n, 0), b(n, 0);
    for (auto &vl : v)
        cin >> vl;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() < v[i])
            s.pop();
        s.push(v[i]);
        a[i] = s.size();
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() < v[i])
            s.pop();
        s.push(v[i]);
        b[i] = s.size();
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, a[i] + b[i] - 1);
    cout << n - ans << endl;
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