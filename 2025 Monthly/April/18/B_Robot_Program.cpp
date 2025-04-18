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
    int n, x, k;
    cin >> n >> x >> k;
    string s, t;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            x--;
        else
            x++;
        if (x == 0)
        {
            for (int j = 0; j <= i; j++)
                t.push_back(s[j]);
            break;
        }
    }
    if (t.empty())
        cout << 0 << endl;
    else
    {
        int count = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                x--;
            else
                x++;
            if (x == 0)
            {
                int size = i + 1;
                k -= t.size();
                count += (k / size);
                break;
                // return;
            }
        }
        cout << count << endl;
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