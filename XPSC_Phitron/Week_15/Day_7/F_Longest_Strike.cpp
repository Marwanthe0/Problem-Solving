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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), ans;
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
        if (m[vl] >= k)
            ans.push_back(1);
        else
            ans.push_back(0);
    }
    int count = 0, l = -1, r = -1;
    pair<int, int> last = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        if (ans[i])
        {
            if (l == -1)
                l = v[i], r = v[i];
            else
                r = v[i];
            if (abs(r - l) > last.second - last.first)
                last.first = min(r, l), last.second = max(r, l);
            count = 0;
        }
        else
        {
            count++;
        }
        if (count >= k)
        {
            l = -1, r = -1;
        }
    }
    if (last.first == -1)
        cout << -1 << endl;
    else
        cout << last.first << " " << last.second << endl;
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