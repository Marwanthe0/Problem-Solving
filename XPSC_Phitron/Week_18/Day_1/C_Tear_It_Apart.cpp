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
int ammago(int n)
{
    int count = 0;
    while (n)
    {
        n /= 2;
        count++;
    }
    return count;
}
void marwan()
{
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    if (m.size() == 1)
        cout << 0 << endl;
    else
    {
        vector<int> ans[26];
        for (int i = 0; i < n; i++)
        {
            ans[s[i] - 'a'].push_back(i);
        }
        int last = INT_MAX;
        for (auto row : ans)
        {
            int mx = INT_MIN;
            int ager = -1;
            for (int i = 0; i < row.size(); i++)
            {
                mx = max(mx, (row[i] - ager) - 1);
                ager = row[i];
                cerr << row[i] << " ";
            }
            if (row.size())
                cerr << endl;
            mx = max((n - 1) - ager, mx);
            // if (mx != INT_MIN)
            last = min(mx, last);
        }
        last = min(last, (int)n);
        cout << ammago(last) << endl;
    }
    cerr << endl;
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