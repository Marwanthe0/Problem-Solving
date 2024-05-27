#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
set<vector<int>> ans;
void generate_subset(vector<int> &v, int i, vector<int> &add)
{
    if (i == v.size())
    {
        ans.insert(add);
        return;
    }
    // ith element not in subset
    generate_subset(v, i + 1, add);
    // ith element included in subset
    add.push_back(v[i]);
    generate_subset(v, i + 1, add);
    add.pop_back();
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> add;
    generate_subset(v, 0, add);
    for (auto x : ans)
    {
        for (auto vl : x)
            cout << vl << " ";
        cout << endl;
    }
    cout << endl;
    ans.clear();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}