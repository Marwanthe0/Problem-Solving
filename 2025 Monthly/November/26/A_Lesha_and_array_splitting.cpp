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
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = i;
        while (i < n && v[i] == 0)
        {
            i++;
        }
        if (i < n)
            ans.push_back({start + 1, i + 1});
    }
    int last = n - 1;
    if (v.back() == 0)
    {
        if (n == 3 && v.front() == 0)
        {
            no;
            return;
        }
        while (last >= 0 && v[last] == 0)
            last--;
        if (last < 0 || v[last] == 0)
        {
            no;
            return;
        }
        ans.pop_back();
        ans.push_back({last + 1, n});
    }
    yes;
    for (auto [x, y] : ans)
        cout << x << " " << y << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}