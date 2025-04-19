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
    if (n & 1)
    {
        vector<int> s, ans;
        for (int i = 1; i <= n; i++)
            s.push_back(i);
        for (int j = 2; j <= n; j++)
        {
            for (int i = 1; i < s.size(); i++)
            {
                if (max(s[i], s[i - 1]) % j == j - 1)
                {
                    cout <<
                }
            }
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
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