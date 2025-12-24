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
    char c;
    cin >> n;
    cin >> c;
    string s;
    cin >> s;
    vector<int> v, t;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
            v.push_back(i + 1), st.insert(i + 1);
        else
            t.push_back(i + 1);
    }
    // for (auto vl : v)
    //     cout << vl << " ";
    // cout << endl;
    if (v.empty())
        cout << 0 << endl;
    else if (v.size() == 1)
    {
        cout << 1 << endl;
        if (v[0] == n)
            cout << v[0] - 1 << endl;
        else
            cout << v[0] + 1 << endl;
    }
    else
    {
        for (auto vl : t)
        {
            bool flag = true;
            for (int i = vl + vl; i <= n; i += vl)
            {
                if (s[i - 1] != c)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << 1 << endl;
                cout << vl << endl;
                return;
            }
        }
        cout << 2 << endl;
        cout << v.back() << " " << v.back() - 1 << endl;
    }
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