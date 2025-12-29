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
    string s;
    cin >> s;
    string temp = s;
    // reverse(all(temp));
    // cerr << temp << endl;
    int count = 0;
    for (auto c : s)
    {
        if (c == '(')
            count++;
    }
    if (n & 1 || (n / 2 != count))
    {
        cout << -1 << endl;
        return;
    }
    stack<pair<char, int>> st;
    vector<int> ans(n, 2);
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            if (s[i] == '(')
                ans[i] = 1;
            st.push({s[i], i});
        }
        else
        {
            if (s[i] == '(')
                ans[i] = 1, st.push({s[i], i});
            else
            {
                if (st.top().first != s[i])
                    ans[i] = 1, st.pop();
            }
        }
    }
    while (!st.empty())
    {
        ans[st.top().second] = 2;
        st.pop();
    }
    set<int> sit;
    for (auto vl : ans)
    {
        sit.insert(vl);
    }
    if (sit.size() == 1)
    {
        for (auto &vl : ans)
            vl = 1;
    }
    else
    {
        reverse(all(s));
        // cerr << s << endl;
        stack<pair<char, int>> st2;
        vector<int> ans2(n, 2);
        for (int i = 0; i < n; i++)
        {
            if (st2.empty())
            {
                if (s[i] == '(')
                    ans2[i] = 1;
                st2.push({s[i], i});
            }
            else
            {
                if (s[i] == '(')
                    ans2[i] = 1, st2.push({s[i], i});
                else
                {
                    if (st2.top().first != s[i])
                        ans2[i] = 1, st2.pop();
                }
            }
        }
        while (!st2.empty())
        {
            ans2[st2.top().second] = 2;
            st2.pop();
        }
        set<int> sit2;
        for (auto vl : ans2)
        {
            sit2.insert(vl);
        }
        if (sit2.size() == 1)
        {
            for (auto &vl : ans2)
                vl = 1;
            cout << sit2.size() << endl;
            for (auto vl : ans2)
                cout << vl << " ";
            cout << endl;
            return;
        }
    }
    cout << sit.size() << endl;
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