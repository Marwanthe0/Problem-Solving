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
    int n, ans = 1;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    set<int> a = {v[0]}, b;
    for (int i = 1; i < n; i++)
    {
        b.insert(v[i]);
        bool flag = true;
        for (auto vl : a)
            if (b.find(vl) == b.end())
            {
                flag = false;
                break;
            }
        if (flag)
        {
            ans++;
            a = b;
            b.clear();
        }
    }
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