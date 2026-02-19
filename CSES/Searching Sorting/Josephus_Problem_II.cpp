#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
void marwan()
{
    int n, k;
    cin >> n >> k;
    pbds<int> pb;
    for (int i = 1; i <= n; i++)
        pb.insert(i);
    int i = 0;
    while (!pb.empty())
    {
        i = (i + k) % pb.size();
        auto it = pb.find_by_order(i);
        cout << *it << " ";
        pb.erase(it);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}