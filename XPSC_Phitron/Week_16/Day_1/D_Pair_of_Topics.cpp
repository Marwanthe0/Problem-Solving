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
    vector<int> a(n), b(n), c(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < n; i++)
        c[i] = a[i] - b[i];
    // sort(all(c));
    for (auto vl : c)
    {
        cerr
            << vl << " ";
    }
    cerr << endl;
    pbds<int>
        pb;
    int ans = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (!pb.empty())
        {
            ans += pb.size() - pb.order_of_key((-1) * c[i]);
            ans -= m[(-1) * c[i]];
        }
        pb.insert(c[i]);
        m[c[i]]++;
        cerr << ans << endl;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}