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
    map<int, int> m;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        m[i] = x, sum += x;
    }
    int df = -1;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int p, val;
            cin >> p >> val;
            if (m.find(p) != m.end())
            {
                sum -= m[p];
            }
            else
                sum -= df;
            m[p] = val;
            sum += val;
        }
        else
        {
            int val;
            cin >> val;
            df = val;
            m.clear();
            sum = n * val;
        }
        cout << sum << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}