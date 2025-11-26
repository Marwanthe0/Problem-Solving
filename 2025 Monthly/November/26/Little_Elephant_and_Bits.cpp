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
    string s, ans;
    cin >> s;
    int n = s.size();
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (flag && s[i] == '0')
            flag = false;
        else
            ans += s[i];
    }
    if (flag)
        ans.pop_back();
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}