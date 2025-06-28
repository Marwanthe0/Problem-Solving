#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
void marwan()
{
    string a, b;
    cin >> a >> b;
    map<char, int> m;
    for (int i = 0; i < (int)b.size(); i++)
    {
        m[b[i]]++;
    }
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            if (m.find(a[i - 1]) == m.end())
            {
                no;
                return;
            }
        }
    }
    yes;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}