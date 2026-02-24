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
vector<string> f(int n)
{
    if (n == 1)
    {
        vector<string> v;
        v.push_back("0");
        v.push_back("1");
        return v;
    }
    vector<string> cur = f(n - 1), rev;
    rev = cur;
    reverse(all(rev));
    for (auto &s : cur)
        s = "0" + s;
    for (auto &s : rev)
    {
        s = "1" + s;
        cur.push_back(s);
    }
    return cur;
}
void marwan()
{
    int n;
    cin >> n;
    vector<string> ans = f(n);
    for (auto s : ans)
        cout << s << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}