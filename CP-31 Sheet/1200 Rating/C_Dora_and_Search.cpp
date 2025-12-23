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
    vector<int> v(n);
    set<int> s;
    for (auto &vl : v)
    {
        cin >> vl;
        s.insert(vl);
    }
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (v[l] == *(s.begin()) || v[l] == *(--s.end()))
            s.erase(v[l++]);
        else if (v[r] == *(s.begin()) || v[r] == *(--s.end()))
            s.erase(v[r--]);
        else
        {
            cout << l + 1 << " " << r + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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