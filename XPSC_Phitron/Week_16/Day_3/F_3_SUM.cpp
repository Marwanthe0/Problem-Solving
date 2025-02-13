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
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl % 10]++;
    }
    vector<int> ans;
    for (auto vl : m)
    {
        if (vl.second == 2)
            ans.push_back(vl.first), ans.push_back(vl.first);
        else if (vl.second > 2)
            ans.push_back(vl.first), ans.push_back(vl.first), ans.push_back(vl.first);
        else
            ans.push_back(vl.first);
    }
    n = ans.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((ans[i] + ans[j] + ans[k]) % 10 == 3)
                {
                    yes;
                    return;
                }
            }
        }
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