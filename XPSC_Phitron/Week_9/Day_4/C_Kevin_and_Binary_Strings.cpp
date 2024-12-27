#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s;
    cin >> s;
    int n = s.size();
    int a = 1, b = s.size(), c, d;
    if (s == string(n, '1'))
        c = 1, d = 1;
    else
    {
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                idx = i + 1;
                int count = 0, temp = i;
                while (temp < n && s[temp] == '0')
                {
                    count++;
                    temp++;
                }
                c = max(1, idx - count);
                break;
            }
        }
        d = c + (n - idx);
    }
    cout << a << " " << b << " " << c << " " << d << endl;
}
int main()
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