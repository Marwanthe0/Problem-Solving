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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 1; i <= n; i++)
        v[i - 1] = i;
    int idx = 0;
    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            v[(idx + a) % n] = b;
        }
        else if (op == 2)
        {
            int a;
            cin >> a;
            a--;
            cout << v[(idx + a) % n] << endl;
        }
        else
        {
            int k;
            cin >> k;
            idx += k;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}