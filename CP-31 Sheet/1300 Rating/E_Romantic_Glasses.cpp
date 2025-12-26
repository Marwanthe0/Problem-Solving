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
    vector<int> v(n), a = {0}, b = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i & 1)
        {
            b.push_back(b.back() + v[i]);
        }
        else
        {
            a.push_back(a.back() + v[i]);
        }
    }
    vector<int> l;
    for (int i = 0; i < a.size(); i++)
    {
        l.push_back(a[i]);
        if (i < b.size())
            l.push_back(b[i]);
    }
    l.erase(l.begin());
    set<int> check;
    for (int i = 1; i < l.size(); i++)
    {
        if (check.find(l[i] - l[i - 1]) != check.end())
        {
            yes;
            cerr << l[i] << ' ' << l[i - 1] << "::" << i << endl;
            return;
        }
        if (l[i] >= l[i - 1])
            check.insert(l[i] - l[i - 1]);
        if (check.find(0) != check.end())
        {
            yes;
            return;
        }
    }
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