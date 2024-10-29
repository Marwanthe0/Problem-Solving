#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<pair<string, string>> v, ans;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < ans.size(); j++)
        {
            if (ans[j].second == v[i].first)
            {
                ans[j].second = v[i].second;
                flag = false;
            }
        }
        if (flag)
            ans.push_back(v[i]);
    }
    cout << ans.size() << endl;
    for (auto vl : ans)
        cout << vl.first << " " << vl.second << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}