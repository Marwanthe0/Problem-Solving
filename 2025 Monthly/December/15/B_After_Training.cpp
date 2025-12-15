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
    int n, m;
    cin >> n >> m;
    vector<int> s;
    if (m & 1)
    {
        int x = (m / 2) + 1;
        s.push_back(x);
        for (int i = 0; i < m / 2; i++)
        {
            s.push_back(x - (i + 1));
            s.push_back(x + (i + 1));
        }
    }
    else
    {
        int x = m / 2;
        int y = x + 1;
        s.push_back(x);
        s.push_back(y);
        for (int i = 0; i < x - 1; i++)
        {
            s.push_back(x - (i + 1));
            s.push_back(y + (i + 1));
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i % m] << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}