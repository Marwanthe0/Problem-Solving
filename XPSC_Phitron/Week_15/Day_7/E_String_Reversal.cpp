#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    string s;
    cin >> s;
    string t = s;
    reverse(all(t));
    // cout << t << endl;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        a[i] = i;
    map<char, vector<int>> m;
    for (int i = 0; i < n; i++)
        m[s[i]].push_back(i);
    for (auto &vl : m)
        sort(all(vl.second), greater<int>());
    for (int i = 0; i < n; i++)
    {
        b[i] = m[t[i]].back();
        m[t[i]].pop_back();
    }
    pbds<int> pb;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!pb.empty())
        {
            ans += pb.size() - pb.order_of_key(b[i]);
        }
        pb.insert(b[i]);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}