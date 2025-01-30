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
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> m;
    for (auto &c : s)
    {
        m[c]++;
    }
    int v = min(m['U'], m['D']);
    int h = min(m['R'], m['L']);
    if (v == 0 and h > 0)
    {
        cout << 2 << endl;
        cout << "RL" << endl;
        return;
    }
    else if (h == 0 and v > 0)
    {
        cout << 2 << endl;
        cout << "UD" << endl;
        return;
    }
    cout << 2 * v + 2 * h << endl;
    for (int i = 0; i < v; i++)
    {
        cout << 'U';
    }
    for (int i = 0; i < h; i++)
    {
        cout << 'R';
    }
    for (int i = 0; i < v; i++)
        cout << 'D';
    for (int i = 0; i < h; i++)
        cout << 'L';
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