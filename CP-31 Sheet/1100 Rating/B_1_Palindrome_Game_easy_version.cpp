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
    int n, count = 0;
    cin >> n;
    string s;
    cin >> s;
    for (auto c : s)
        if (c == '0')
            count++;
    if (count == 1 || count % 2 == 0)
        cout << "BOB" << endl;
    else
        cout << "ALICE" << endl;
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