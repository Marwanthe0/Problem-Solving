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
vector<vector<int>> ans;
void f(int idx, vector<int> &v, int k, int sum, vector<int> &a)
{
    if (sum == k)
    {
        ans.push_back(a);
        return;
    }
    if (idx >= v.size() || sum > k)
    {
        return;
    }
    a.push_back(v[idx]);
    f(idx + 1, v, k, sum + v[idx], a);
    a.pop_back();
    f(idx + 1, v, k, sum, a);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> a;
    sort(candidates.begin(), candidates.end());
    f(0, candidates, target, 0, a);
    sort(ans.begin(), ans.end());
    return ans;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int target;
    cin >> target;
    vector<vector<int>>
        ans = combinationSum2(v, target);
    unique(all(ans));
    for (auto row : ans)
    {
        for (auto vl : row)
            cout << vl << " ";
        cout << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}