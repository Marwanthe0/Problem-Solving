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
    stack<int> st;
    map<char, int> m = {
        {'(', -1},
        {'{', -2},
        {'[', -3},
        {')', 1},
        {'}', 2},
        {']', 3},
    };
    for (auto c : s)
    {
        if (st.empty())
        {
            if (m[c] < 0)
                st.push(m[c]);
            else
            {
                no;
                return;
            }
        }
        else
        {
            if (m[c] < 0)
            {
                st.push(m[c]);
            }
            else
            {
                if (m[c] == st.top() * (-1))
                    st.pop();
                else
                {
                    no;
                    return;
                }
            }
        }
    }
    if (st.empty())
        yes;
    else
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