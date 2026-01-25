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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int x = n;
    int l = 1;
    while (v[l] == x)
    {
        l++;
        x--;
    }
    for (int i = l; i <= n; i++)
    {
        if (v[i] == x)
        {
            reverse(v.begin() + l, v.begin() + i + 1);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
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