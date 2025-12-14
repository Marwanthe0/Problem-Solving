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
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
        {
            a.push_back(x);
        }
        else
            b.push_back(x);
    }
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    if (a.empty())
    {
        for (int i = 0; i < n; i++)
            cout << 0 << ' ';
        cout << endl;
        return;
    }
    int x = a[0], y = 0, idx = 0;
    vector<int> ans = {x};
    for (int i = 2; i <= n; i++)
    {
        if (idx < b.size())
        {
            y += b[idx++];
            ans.push_back(x + y);
        }
    }
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