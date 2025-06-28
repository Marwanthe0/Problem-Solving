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
    vector<int> v(n), tmp;
    for (auto &vl : v)
        cin >> vl;
    if (v.front() * 2 >= v.back())
    {
        cout << 2 << endl;
        return;
    }
    for (auto vl : v)
        if (vl >= v.front() && vl <= v.back())
            tmp.push_back(vl);
    v = tmp, n = tmp.size();
    sort(all(v));
    for (auto vl : v)
        cerr << vl << " ";
    cerr << endl;
    int i = 0, count = 0, last = v[i];
    while (i < n)
    {
        if (v[i] <= (2 * last))
            i++;
        else
        {
            count++, last = v[i - 1], i++;
        }
        cerr << v[i] << " " << last << endl;
    }
    if ((last * 2) >= v.back())
    {
        cout << count + 2 << endl;
    }
    else
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