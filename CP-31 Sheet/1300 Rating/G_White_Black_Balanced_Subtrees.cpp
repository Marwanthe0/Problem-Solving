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
vector<pair<int, int>> pf(5000);
pair<int, int> bfs(int x, map<int, vector<int>> &m, string &s)
{
    queue<int> q;
    int a = 0, b = 0;
    q.push(x);
    // cerr << x << endl;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (auto vl : m[f])
        {
            if (pf[vl].first != -1)
            {
                a += pf[vl].first, b += pf[vl].second;
                continue;
            }
            q.push(vl);
        }
        if (s[f] == 'W')
            a++;
        else
            b++;
        // cerr << f << " ";
    }
    // cerr << endl;
    return pf[x] = {a, b};
}
void marwan()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        pf[i] = {-1, -1};
    }
    vector<int> v(n + 2);
    string s;
    set<int> st;
    map<int, vector<int>> m;
    for (int i = 2; i <= n; i++)
    {
        cin >> v[i];
        m[v[i]].push_back(i);
        st.insert(v[i]);
    }
    cin >> s;
    s = "0" + s;
    int ans = 0;
    // for (int i = 2; i <= n + 1; i++)
    //     cout << s[i];
    // cout << endl;
    for (auto it = st.rbegin(); it != st.rend(); it++)
    {
        auto vl = *it;
        pair<int, int> a = bfs(vl, m, s);
        if (a.first == a.second)
            ans++;
        // cerr << vl.first << " " << a.first << " " << a.second << endl;
    }
    // cerr << endl;
    cout << ans << endl;
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