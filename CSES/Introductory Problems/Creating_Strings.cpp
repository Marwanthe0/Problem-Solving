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
void f(int i, string &s, string &t, vector<string> &ans, set<int> &st)
{
    if (i < 0)
    {
        ans.push_back(t);
        return;
    }
    for (int j = 0; j < s.size(); j++)
    {
        if (!st.count(j))
        {
            st.insert(j);
            t.push_back(s[j]);
            f(i - 1, s, t, ans, st);
            st.erase(j);
            t.pop_back();
        }
    }
}
void marwan()
{
    string s;
    cin >> s;
    string t;
    vector<string> ans;
    set<int> st;
    f(s.size() - 1, s, t, ans, st);
    set<string> last(all(ans));
    cout << last.size() << endl;
    for (auto vl : last)
        cout << vl << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}