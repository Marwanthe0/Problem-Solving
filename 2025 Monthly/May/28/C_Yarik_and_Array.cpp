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
int ans(vector<int> v, int n)
{
    set<int> s;
    s.insert(0);
    int sum = 0, mn = INT_MIN;
    for (auto vl : v)
    {
        // cerr << vl << " ";
        sum += vl;
        mn = max({mn, sum - *s.begin(), vl});
        s.insert(sum);
    }
    // cerr << endl;
    return mn;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n), temp;
    for (auto &vl : v)
        cin >> vl;
    temp.push_back(v.front());
    int mn = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if ((v[i] & 1) == ((v[i - 1] & 1)))
        {
            mn = max(mn, ans(temp, temp.size()));
            temp.clear();
        }
        temp.push_back(v[i]);
    }
    if (!temp.empty())
    {
        mn = max(mn, ans(temp, temp.size()));
    }
    cout << mn << endl;
    // cerr << endl;
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