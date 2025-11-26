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
    vector<int> v, a, b;
    string s;
    cin >> s;
    for (auto c : s)
        v.push_back(c - '0');
    if (is_sorted(all(v)))
    {
        cout << 0 << endl;
        return;
    }
    bool flag = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == 0)
            flag = 1;
        if (flag && v[i])
            a.push_back(i);
    }
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i])
            flag = 1;
        if (flag && v[i] == 0)
            b.push_back(i);
    }
    sort(all(a));
    sort(all(b), greater<int>());
    for (auto vl : a)
        cerr << vl;
    cerr << endl;
    for (auto vl : b)
        cerr << vl;
    cerr << endl;
    vector<int> ans;
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        ans.push_back(a[i]);
        ans.push_back(b[i]);
    }
    cout << 1 << endl;
    cout << ans.size() << " ";
    sort(all(ans));
    for (auto vl : ans)
        cout << vl + 1 << " ";
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