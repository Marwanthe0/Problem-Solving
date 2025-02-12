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
    vector<int> a(n + 1), b(n);
    map<int, int> m;
    forn
    {
        int x;
        cin >> x;
        a[x] = i;
    }
    int count = 0, cnt = 0;
    pbds<int> ans;
    forn
    {
        int x;
        cin >> x;
        if (((a[x] + (ans.size() - ans.order_of_key(a[x]))) > i))
        {
            cnt++;
            count++;
            ans.insert(a[x]);
        }
        else
            cnt = max(cnt - 1, 0ll);
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}