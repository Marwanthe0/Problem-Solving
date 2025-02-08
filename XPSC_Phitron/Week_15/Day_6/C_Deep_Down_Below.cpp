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
bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) { return a.first < b.first; }
bool ok(int m, vector<int> &ans)
{
    int x = m;
    for (auto vl : ans)
    {
        // cerr << vl << " " << x << endl;
        if (vl >= x)
            return false;
        else
            x++;
    }
    return true;
};
void marwan()
{
    int n;
    cin >> n;
    vector<pair<int, vector<int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<int> temp;
        for (int j = 0; j < x; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        int mx = temp[0] + 1, y = temp[0] + 1, cnt = 0;
        for (int j = 0; j < x; j++)
        {
            if (mx > temp[j])
                mx++;
            else
                mx = (temp[j] - j) + 1, y = max(y, (temp[j] - j) + 1);
        }
        cerr << y << ":::";
        for (auto vl : temp)
            cerr << vl << " ";
        cerr << endl;
        v[i].first = y, v[i].second = temp;
    }
    cerr << endl;
    sort(all(v), cmp);
    vector<int> ans;
    for (auto row : v)
    {
        // cout << row.first << "::";
        for (auto vl : row.second)
            ans.push_back(vl);
    }
    int l = 1, r = 1e12, mid, last = 0;
    while (l <= r)
    {
        mid = l + ((r - l) / 2);
        // cerr << mid << endl;
        if (ok(mid, ans))
        {
            last = mid, r = mid - 1;
        }
        else
            l = mid + 1;
    }
    // for (auto vl : ans)
    //     cerr << vl << " ";
    // cerr << endl;
    cout << last << endl;
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