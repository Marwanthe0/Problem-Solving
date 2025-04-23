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
int num(string s)
{
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    string s = to_string(n), t = s;
    for (int i = 1; i < k; i++)
        s += t;
    if (s.size() > 18 || n == 1 && k == 1)
    {
        no;
        return;
    }
    else
    {
        int x = stoll(s);
        for (int i = 2; i * i <= x; i++)
        {
            if ((x % i) == 0)
            {
                no;
                return;
            }
        }
        yes;
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