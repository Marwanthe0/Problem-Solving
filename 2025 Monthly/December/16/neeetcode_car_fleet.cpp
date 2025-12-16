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
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < position.size(); i++)
        v.push_back({position[i], speed[i]});
    sort(v.begin(), v.end());
    vector<int> ans;
    for (auto [x, y] : v)
    {
        ans.push_back((target - x) / y + ((target - x) % y != 0));
    }
    int locmin = ans.back();
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] < locmin)
            ans[i] = locmin;
        locmin = max(locmin, ans[i]);
    }
    for (auto vl : ans)
        cerr << vl << " ";
    cerr << endl;
    set<int> x(ans.begin(), ans.end());
    return x.size();
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    cout << carFleet(k, a, b) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}