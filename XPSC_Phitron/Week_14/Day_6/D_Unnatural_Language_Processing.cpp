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
map<char, int> m = {{'b', 1}, {'c', 1}, {'d', 1}};
void marwan()
{
    int n;
    cin >> n;
    string s, a;
    cin >> s;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (count >= 2)
        {
            if (m[s[i]] != m[s[i + 1]])
            {
                if (a.back() != '.')
                    a.push_back('.');
                a.push_back(s[i]);
                count = 0;
            }
            else
            {
                a.push_back(s[i]);
                a.push_back('.');
                count = 1;
            }
        }
        else
            a.push_back(s[i]);
        count++;
    }
    a.push_back(s.back());
    cout << a << endl;
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