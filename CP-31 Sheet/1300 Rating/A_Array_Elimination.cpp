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
    vector<int> v(n), a;
    int x = 0;
    set<int> s;
    for (auto &vl : v)
    {
        cin >> vl;
        x = max(x, __lg(vl));
        s.insert(vl);
    }
    if (s.size() == 1)
    {
        if (*s.begin() == 0)
        {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            set<int> fact = {1, n};
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    if (n / i != i)
                        fact.insert(n / i);
                    fact.insert(i);
                }
            }
            for (auto vl : fact)
                cout << vl << " ";
            cout << endl;
        }
        return;
    }
    vector<int> t;
    for (auto vl : v)
        if (vl)
            t.push_back(vl);
    v = t, n = t.size();
    vector<int> fact = {n};
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
                fact.push_back(n / i);
            fact.push_back(i);
        }
    }
    sort(all(fact));
    vector<vector<int>> ans;
    for (auto vl : v)
    {
        vector<int> temp;
        for (int i = x; i >= 0; i--)
        {
            // cout << ((vl >> i) & 1);
            temp.push_back((vl >> i) & 1);
        }
        ans.push_back(temp);
        // cout << endl;
    }
    set<int> final = {1};
    vector<int> gc;
    int count = 0;
    for (int i = 0; i < ans[0].size(); i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (ans[j][i])
                count++;
        }
        gc.push_back(count);
    }
    int g = gc.front();
    for (auto vl : gc)
    {
        g = __gcd(g, vl);
        cerr << vl << " ";
    }
    cerr << endl;
    final.insert(g);
    for (int i = 2; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            final.insert(i);
            final.insert(g / i);
        }
    }
    for (auto vl : final)
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