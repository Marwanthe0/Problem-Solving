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
    vector<int> v(n), pf(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i)
            pf[i] = pf[i - 1] + (v[i] == 2);
        else
            pf[i] = (v[i] == 2);
        cout << pf[i] << " ";
    }
    vector<int> thr, one;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 3)
            thr.push_back(i);
        else if (v[i] == 1)
            one.push_back(i);
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