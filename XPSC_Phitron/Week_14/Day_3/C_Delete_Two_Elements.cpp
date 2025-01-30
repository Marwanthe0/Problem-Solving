#include <bits/stdc++.h>
using namespace std;
#define int long double
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
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        s.insert(vl);
        m[vl]++;
    }
    int sum = (int)0;
    for (auto vl : v)
        sum += (int)vl;
    int k = (int)sum - ((sum / n) * (n - (int)2));
    v.clear();
    for (auto vl : s)
        v.push_back(vl);
    n = v.size();
    long long l = 0ll, r = n - 1ll, count = 0ll;
    while (l <= r)
    {
        if (v[l] + v[r] == k)
        {
            if (l != r)
                count += (m[v[l]] * m[v[r]]), l++, r--;
            else
                count += (m[v[l]] * (m[v[r]] - 1)) / 2, l++, r--;
        }
        else if (v[l] + v[r] < k)
        {
            l++;
        }
        else
            r--;
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