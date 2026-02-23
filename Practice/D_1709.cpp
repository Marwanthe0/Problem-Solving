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
int ps(int x) { return x - 1; }
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(2 * n), r, pos((2 * n) + 1);
    vector<pair<int, int>> ans;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
        pos[v[i]] = i;
        // cerr << v[i] << " " << i << endl;
    }
    for (int i = 1; i <= (2 * n); i++)
    {
        int cur = pos[i], nxt = ps(i);
        cerr << i << " " << cur << " " << nxt << endl;
        while ((cur % n) != (nxt % n))
        {
            if ((cur % n) > (nxt % n))
            {
                swap(pos[v[cur]], pos[v[cur - 1]]);
                swap(v[cur], v[cur - 1]);
                ans.push_back({(cur < n ? 1 : 2), (cur % n)});
                cur--;
            }
            else
            {
                swap(pos[v[cur]], pos[v[cur + 1]]);
                swap(v[cur], v[cur + 1]);
                ans.push_back({(cur < n ? 1 : 2),
                               (cur % n) + 1});
                cur++;
            }
        }
        if (cur != nxt)
        {
            swap(pos[v[cur]], pos[v[cur + (cur < n ? n : -n)]]);
            swap(v[cur], v[cur + (cur < n ? n : -n)]);
            ans.push_back({3, 1 + (cur % n)});
            cur = cur + (cur < n ? n : -n);
        }
        pos[i] = cur;
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
        cout << x << " " << y << endl;
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