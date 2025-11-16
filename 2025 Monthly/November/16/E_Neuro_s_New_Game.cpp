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
    vector<int> v(n, -1);
    int cnt = 0;
    for (auto c : s)
        if (c == '1')
            cnt++;
    if (cnt == 0 || cnt == n)
    {
        cout << -1 << endl;
        return;
    }
    int x = n - 1, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            v[i] = x--;
            if (s[(i + 1) % n] == '0')
                v[(i + 1) % n] = y++;
        }
    }
    for (auto &vl : v)
        if (vl == -1)
            vl = y++;
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}