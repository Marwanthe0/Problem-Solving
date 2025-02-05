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
    int x, y;
    cin >> x >> y;
    string s;
    for (int i = 0; i < x / 2; i++)
    {
        s.push_back('1');
    }
    for (int i = 0; i < y / 2; i++)
        s.push_back('2');
    cout << s;
    reverse(all(s));
    cout << s << endl;
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