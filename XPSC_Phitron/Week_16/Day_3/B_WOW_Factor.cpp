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
    string s, a;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'v')
        {
            int count = 0;
            while (i < n && s[i] == 'v')
                i++, count++;
            while (--count)
                a.push_back('w');
            i--;
        }
        else
            a.push_back('o');
    }
    s = a, n = a.size();
    int sum = 0, last = 0, o = 0, flag = 0;
    // cout << a << endl;
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'w')
            flag = 1;
        if (flag)
        {
            if (s[i] == 'o')
                o++;
            else
            {
                ans.push_back(o);
            }
        }
    }
    int ss = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ((i * (ans[i])) - ss);
        ss += ans[i];
    }
    cout << sum << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}