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
    for (auto &vl : v)
        cin >> vl;
    vector<int> a = {0}, b = {0};
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            b.push_back(b.back() + v[i]);
        else
            a.push_back(a.back() + v[i]);
    }
    // for (auto vl : a)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : b)
    //     cerr << vl << " ";
    // cerr << endl;
    // cerr << endl;
    set<int> s;
    for (int i = 0; i < b.size(); i++)
    {
        if (s.find(b[i] - a[i]) != s.end())
        {
            yes;
            return;
        }
        if (i < a.size() - 1 && s.find(b[i] - a[i + 1]) != s.end())
        {
            yes;
            return;
        }
        s.insert(b[i] - a[i]);
        if (i + 1 < a.size())
            s.insert(b[i] - a[i + 1]);
        // if (i > 0)
        //     s.insert(b[i] - a[i - 1]);
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