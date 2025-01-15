#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
bool mx(map<int, int> &m, int key)
{
    int mn = INT_MIN, val;
    for (auto vl : m)
    {
        if (vl.second >= mn)
        {
            mn = vl.second, val = vl.first;
        }
    }
    return mn == m[key];
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    int count = 0;
    if (mx(m, k))
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        vector<int> fr;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == k)
                fr.push_back(i);
        }
        for (int i = 0; i < fr.size(); i++)
        {
            map<int, int> e, f;
            for (int j = 0; j <= fr[i]; j++)
            {
                e[v[j]]++;
            }
            if (mx(e, k))
            {
                cout << 1 << endl;
                return;
            }
            for (int j = fr[i]; j < n; j++)
            {
                f[v[j]]++;
            }
            if (mx(f, k))
            {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
    }
}
int main()
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