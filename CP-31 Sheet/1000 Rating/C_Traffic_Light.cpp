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
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    s += s;
    int dist = INT_MIN, lastg = -1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'g')
            lastg = i;
        if (lastg != -1 && s[i] == c)
        {
            dist = max(dist, lastg - i);
        }
    }
    cout << dist << endl;
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