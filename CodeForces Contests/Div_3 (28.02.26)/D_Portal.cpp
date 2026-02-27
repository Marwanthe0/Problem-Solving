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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    v.insert(v.begin() + y, 0);
    v.insert(v.begin() + x, 0);
    n = v.size();
    int a = -1, b;
    for (int i = 0; i < v.size(); i++)
    {
        if (a == -1 && v[i] == 0)
            a = i;
        else if (v[i] == 0)
            b = i;
    }
    int mn = a + 1;
    vector<int> majer;
    for (int i = a + 1; i < b; i++)
    {
        if (v[i] < v[mn])
        {
            mn = i;
        }
    }
    for (int i = mn; i < b; i++)
    {
        majer.push_back(v[i]);
    }
    for (int i = a + 1; i < mn; i++)
        majer.push_back(v[i]);
    int minx = majer.front();
    vector<int> bairer, ans;
    for (int i = 0; i < a; i++)
        bairer.push_back(v[i]);
    for (int i = b + 1; i < v.size(); i++)
        bairer.push_back(v[i]);
    bool flag = false;
    for (auto vl : bairer)
    {
        if (flag || vl <= minx)
        {
            ans.push_back(vl);
        }
        else
        {
            for (auto val : majer)
                ans.push_back(val);
            ans.push_back(vl);
            flag = true;
        }
    }
    if (!flag)
    {
        for (auto val : majer)
            ans.push_back(val);
    }
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
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