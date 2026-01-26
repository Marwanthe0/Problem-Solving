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
    string s;
    cin >> s;
    int l = 0, r = 0, a = 0, b = 0, c = 0;
    queue<int> q;
    while (r < n)
    {
        if (s[r] == '1')
            a++;
        else if (s[r] == '0')
            b++;
        else
        {
            c++;
            q.push(r);
        }
        if (r - l + 1 == k)
        {
            
        }
        r++;
    }
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