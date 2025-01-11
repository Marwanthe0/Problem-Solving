#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    vector<int> v(n), a;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // if (i)
        //     a.push_back(v[i] - v[i - 1]);
    }
    sort(all(v));
    for (int i = 1; i < n; i++)
        a.push_back(v[i] - v[i - 1]);
    v.clear();
    v = a, n = a.size();
    int l = 0, r = n - 1, x = v[0], y = v[r], sum = accumulate(all(v), 0), z = 0, ans = INT_MAX;
    while (l < r)
    {
        z = sum - (x + y);
        ans = min(ans, max({x - v[l], y - v[r], z}));
        if (x < y)
        {
            x += v[++l];
        }
        else
            y += v[--r];
        // cout << ans << " ";
    }
    if (ans != INT_MAX)
        cout << ans / 2 + ans % 2 << endl;
    else
        cout << 0 << endl;
    // for (auto vl : v)
    //     cerr
    //         << vl << " ";
    // cerr << endl;
}
int main()
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