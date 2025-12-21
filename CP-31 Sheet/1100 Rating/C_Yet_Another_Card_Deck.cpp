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
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    set<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (s.find(x) == s.end())
            v.push_back(x), m[x] = i + 1;
        s.insert(x);
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        for (auto &vl : m)
        {
            if (vl.second < m[x])
                vl.second++;
        }
        cout << m[x] << " ";
        m[x] = 1;
    }
    cout << endl;
    // for (auto vl : v)
    //     cout
    //         << vl
    //         << " ";
    // cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}