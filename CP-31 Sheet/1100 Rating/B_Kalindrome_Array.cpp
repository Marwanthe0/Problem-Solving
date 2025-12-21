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
bool pal(vector<int> &v)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        if (v[l] != v[r])
            return false;
        l++, r--;
    }
    return true;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int l = 0, r = n - 1;
    while (l <= r && v[l] == v[r])
    {
        l++, r--;
    }
    vector<int> a, b;
    for (auto vl : v)
    {
        if (vl != v[l])
            a.push_back(vl);
        if (vl != v[r])
            b.push_back(vl);
    }
    if (pal(a) || pal(b))
    {
        yes;
    }
    else
        no;
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