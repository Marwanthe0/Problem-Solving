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
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        m[l]++, m[r + 1]--;
    }
    int sum = 0;
    for (auto [x, y] : m)
    {
        m[x] += sum;
        sum += y;
    }
    vector<int> ans(n + 1, 0);
    pair<int, int> last;
    int i = 0;
    for (auto [x, y] : m)
    {
        // cerr << x << " " << y << endl;
        i++;
        if (i > 1)
        {
            ans[last.second] += (x - last.first);
            // cout << last.second << " " << ans[last.second] << endl;
        }
        last = {x, y};
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}