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
    int count = 0, id = 0;
    for (int i = 0; i <= (k / 2); i++, id++)
    {
        map<char, int> m;
        char mf;
        int f = 0, d = k - (i + 1);
        for (int j = i; j < n; j += k)
        {
            m[s[j]]++;
            // cerr << s[j] << j << " ";
            if (m[s[j]] > f)
                f = m[s[j]], mf = s[j];
            if (d > 0)
            {
                int x = j + d - id;
                m[s[x]]++;
                // cerr << s[x] << x << " ";
                if (m[s[x]] > f)
                    f = m[s[x]], mf = s[x];
            }
        }

        // cerr << mf << " " << endl;
        for (int j = i; j < n; j += k)
        {
            int x = j + d - id;
            if (s[j] != mf)
                s[j] = mf, count++;
            if (d > 0 && s[x] != mf)
                s[x] = mf, count++;
        }
    }
    // cerr << endl;
    cout << count << endl;
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