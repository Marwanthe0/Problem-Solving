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
    string s;
    cin >> s;
    if (is_sorted(all(s)))
    {
        no;
        return;
    }
    yes;
    char mx = s.front();
    int mxidx = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] < mx)
        {
            cout << mxidx + 1 << " " << i + 1 << endl;
            return;
        }
        else
        {
            mx = s[i], mxidx = i;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}