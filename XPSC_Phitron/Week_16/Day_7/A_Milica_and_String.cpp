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
    int n, k, count = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto c : s)
        if (c == 'A')
            a++;
        else
            b++;
    if (b < k)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                cnt++;
            if (cnt + b == k)
            {
                cout << 1 << endl;
                cout << i + 1 << " B" << endl;
                return;
            }
        }
    }
    else
    {
        if (b == k)
        {
            cout << 0 << endl;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                b--;
            }
            if (b == k)
            {
                cout << 1 << endl;
                cout << i + 1 << " A" << endl;
                return;
            }
        }
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