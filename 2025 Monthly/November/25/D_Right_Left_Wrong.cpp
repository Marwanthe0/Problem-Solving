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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    string s;
    cin >> s;
    // int last = -1, ans = 0, sum = 0, mark = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (s[i] == 'L')
    //     {
    //         mark = 0;
    //     }
    //     if (!mark)
    //         sum += v[i];
    //     if (!mark && s[i] == 'R')
    //     {
    //         mark = 1, ans += sum, sum = 0;
    //     }
    // }
    s = "a" + s;
    v.insert(v.begin(), 0);
    vector<int> pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + v[i];
    for (auto vl : pf)
        cerr << vl << " ";
    cerr << endl;
    int l = 1, r = n, ans = 0;
    while (l < r)
    {
        while (l <= n && s[l] != 'L')
            l++;
        while (r >= 1 && s[r] != 'R')
            r--;
        if (((l >= 1 && l <= n && r >= 1 && r <= n) && l < r) && s[l] == 'L' && s[r] == 'R')
        {
            cerr << l << " " << r << endl;
            ans += (pf[r] - pf[l - 1]), l++, r--;
        }
    }
    cout << ans << endl;
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