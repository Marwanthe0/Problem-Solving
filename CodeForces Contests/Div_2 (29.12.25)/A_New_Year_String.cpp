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
    for (int i = 0; i < n - 3; i++)
    {
        if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '6')
        {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 0; i < n - 3; i++)
    {
        if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '5')
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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