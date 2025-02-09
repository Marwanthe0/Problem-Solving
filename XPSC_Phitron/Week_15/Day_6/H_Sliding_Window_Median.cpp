#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    pbds<pair<int, int>> p;
    int l = 0, r = 0;
    vector<int> ans;
    while (r < n)
    {
        p.insert({v[r], r});
        if (r - l + 1 == k)
        {
            ans.push_back(p.find_by_order(k / 2 + ((k % 2 == 0) ? -1 : 0))->first);
            p.erase(p.find_by_order(p.order_of_key({v[l], l})));
            l++;
        }
        cerr << endl;
        r++;
    }
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}