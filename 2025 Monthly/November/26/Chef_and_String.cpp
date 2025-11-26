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
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
        {
            int c = i + 1, r = 0, l = 0, d = i - 1, k = ((i) ? i - 1 : n - 1);
            while(s[c % n] == 'I')
                c++;
            while()
            while (s[c % n] == s[(i + 1) % n] && (c % n) != i)
                c++, r++;
            if (d < 0)
                d = n - 1;
            while (s[d % n] == s[k] && d != i)
            {
                d--, l++;
                if (d < 0)
                    d = n - 1;
            }
            if (r > l)
                s[i] = s[(i + 1) % n];
            else
                s[i] = s[k];
        }
    }
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