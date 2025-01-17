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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<int> vis(n, 0);
    for (auto &vl : v)
        cin >> vl;
    vector<pair<string, string>> ans;
    for (int i = 0; i < n; i++)
    {
        string s = v[i];
        if (!vis[i])
        {
            for (int j = i + 1; j < n; j++)
            {
                if (!vis[j])
                {
                    string t = v[j];
                    reverse(all(t));
                    if (s == t)
                    {
                        vis[i] = 1, vis[j] = 1;
                        ans.push_back({v[i], v[j]});
                    }
                }
            }
        }
    }
    string mid = "";
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            string t = v[i];
            reverse(all(t));
            if (t == v[i])
            {
                mid = t;
            }
        }
    }
    cout << ans.size() * 2 * m + mid.size() << endl;
    for (auto vl : ans)
        cout << vl.first;
    if (mid.size())
        cout << mid;
    reverse(all(ans));
    for (auto vl : ans)
        cout << vl.second;
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}