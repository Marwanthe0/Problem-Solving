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
    int n, k;
    string s;
    cin >> s;
    n = s.size();
    cin >> k;
    int count = n, x = (n * (n + 1)) / 2, del = 0, dp = 0;
    for (int i = 1; i <= x && count > 0; i += count, count--)
    {
        if (i + count > k)
        {
            dp = k - i;
            break;
        }
        del++;
    }
    vector<int> t;
    stack<pair<char, int>> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && s[i] < st.top().first)
        {
            t.push_back(st.top().second);
            st.pop();
        }
        st.push({s[i], i});
    }
    while (!st.empty())
    {
        t.push_back(st.top().second);
        st.pop();
    }
    reverse(all(t));
    // for (auto vl : t)
        //cerr << vl << " ";
    //cerr << endl;
    vector<int> m(t.begin(), t.begin() + (t.size() - del));
    //cerr << del << " " << dp << endl;
    sort(all(m));
    // for (auto vl : m)
        //cerr << vl << " ";
    //cerr << endl;
    cout << s[m[dp]];
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