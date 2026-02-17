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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    string s;
    cin >> s;
    b.push_back(INT_MIN);
    b.push_back(INT_MAX);
    sort(all(a));
    sort(all(b));
    int l = 0, r = 0;
    vector<pair<int, int>> t(n);
    while (l < n)
    {
        while (r < b.size() && b[r] < a[l])
            r++;
        r--;
        t[l] = {b[r] - a[l], b[r + 1] - a[l]};
        l++;
    }
    int x = 0, idx = 0;
    vector<int> morbe;
    map<int, int> mp;
    for (auto c : s)
    {
        if (c == 'L')
            x--;
        else
            x++;
        morbe.push_back(x);
        if (x && !mp.count(x))
            mp[x] = idx;
        //cerr << morbe.back();
        idx++;
    }
    vector<int> ans(k, 0);
    for (auto [x, y] : t)
    {
        if (mp.count(x) && mp.count(y))
        {
            int mn = min(mp[x], mp[y]);
            ans[mn]--;
        }
        else if (mp.count(x))
        {
            ans[mp[x]]--;
        }
        else if (mp.count(y))
            ans[mp[y]]--;
        //cerr << x << " " << y << endl;
    }
    ans[0] += n;
    for (int i = 1; i < ans.size(); i++)
        ans[i] += ans[i - 1];
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
    //cerr << endl;
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