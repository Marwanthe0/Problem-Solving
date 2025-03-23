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
    vector<int> v(n + 1, 0);
    while (k--)
    {
        int op;
        cin >> op;
        if (op)
        {
            int x, y;
            cin >> x >> y;
            x++, y++;
            cout << v[y] - v[x - 1] << endl;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}