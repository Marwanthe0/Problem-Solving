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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n + m);
    for (auto &vl : v)
        cin >> vl;
    int count = 0, i = 0;
    vector<int> temp = v, tt;
    while (++i)
    {
        int mn1 = (min_element(v.begin(), v.begin() + n) - v.begin()), mn2 = min_element(v.begin() + n, v.end()) - v.begin();
        int mx1 = (max_element(v.begin(), v.begin() + n) - v.begin()), mx2 = max_element(v.begin() + n, v.end()) - v.begin();
        if (i & 1)
        {
            if (temp[mn1] < temp[mx2])
                swap(temp[mn1], temp[mx2]);
        }
        else
        {
            if (temp[mn2] < temp[mx1])
                swap(temp[mn2], temp[mx1]);
        }
        if (tt.size() && tt == temp)
        {
            break;
        }
        if (i >= k)
        {
            cerr << "BReak" << i << endl;
            for (auto vl : temp)
                cerr << vl << " ";
            cerr << endl;
            cout << accumulate(temp.begin(), temp.begin() + n, 0ll) << endl;
            return;
        }
        tt = v;
        v = temp;
    }
    i--;
    if ((i % 2) == (k % 2))
    {
        cout << accumulate(v.begin(), v.begin() + n, 0ll) << endl;
    }
    else
    {
        int mn1 = (min_element(v.begin(), v.begin() + n) - v.begin()), mn2 = min_element(v.begin() + n, v.end()) - v.begin();
        int mx1 = (max_element(v.begin(), v.begin() + n) - v.begin()), mx2 = max_element(v.begin() + n, v.end()) - v.begin();
        if (i & 1)
        {
            if (v[mn2] < v[mx1])
                swap(v[mn2], v[mx1]);
        }
        else
        {
            if (v[mn1] < v[mx2])
                swap(v[mn1], v[mx2]);
        }
        cout << accumulate(v.begin(), v.begin() + n, 0ll) << endl;
    }
    for (auto vl : v)
        cerr << vl << " ";
    cerr << endl;
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