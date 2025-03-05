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
int ans(int i, string s, int k, int o, set<char> &st, int cnt)
{
    if (i >= s.size())
    {
        return o;
    }
    if (st.find(s[i]) != st.end())
    {
        return ans(i + 1, s, k, o, st, cnt);
    }
    else
    {
        st.insert(s[i]);
        int op1 = ans(i + 1, s, k, o + k, st, cnt);
        st.erase(s[i]);
        int op2 = ans(i + 1, s, k, o, st, cnt + 1) + cnt;
        return min(op1, op2);
    }
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = '0' + s;
    set<char> st;
    cout << ans(1, s, k, 0, st, 1) << endl;
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