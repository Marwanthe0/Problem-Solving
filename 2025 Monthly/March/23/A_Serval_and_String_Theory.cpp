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
    int n, k;
    cin >> n >> k;
    map<char, int> m;
    string s;
    cin >> s;
    for (auto vl : s)
        m[vl]++;
    if (m.size() == 1)
    {
        no;
        return;
    }
    string t = s;
    reverse(all(t));
    string a, b;
    for (int i = 0; i <= n / 2; i++)
    {
        if (s[i] >= s[n - i - 1])
            a.push_back(s[i]), b.push_back(s[n - i - 1]);
    }
    if (s < t)
    {
        yes;
        return;
    }
    // if (s == t)
    // {
    //     no;
    //     return;
    // }
    // a.pop_back(), b.pop_back();
    sort(all(b));
    sort(all(a), greater<char>());
    // for (auto vl : a)
    //     cout << vl << " ";
    // cout << endl;
    // for (auto vl : b)
    //     cout << vl << " ";
    // cout << endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (k > 0 || a[i] < b[i])
        {
            continue;
        }
        else
        {
            no;
            return;
        }
        k--;
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