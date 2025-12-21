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
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    for (auto [x, y] : m)
    {
        set<char> st;
        for (auto c : s)
        {
            if (c == x)
            {
                if (st.empty())
                    st.insert(c);
                else
                {
                    if (st.size() != m.size())
                    {
                        no;
                        return;
                    }
                    st.clear();
                    st.insert(c);
                }
            }
            else if (!st.empty())
                st.insert(c);
        }
    }
    yes;
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