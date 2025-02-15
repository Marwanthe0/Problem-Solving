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
    int n, k;
    cin >> n >> k;
    k *= (-1);
    vector<int> v(n);
    set<int> s;
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        vl *= -1;
        s.insert(vl);
        m[vl]++;
    }
    int temp = k, count = 1;
    while (!s.empty())
    {
        auto it = lower_bound(all(s), temp);
        if (it == s.end())
        {
            temp = k;
            count++;
        }
        else
        {
            temp -= *it;
            m[*it]--;
            if (m[*it] <= 0)
            {
                m.erase(*it);
                s.erase(it);
            }
        }
    }
    cout << count << endl;
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