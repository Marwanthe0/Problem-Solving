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
    vector<int> v(n), z;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (!v[i])
            z.push_back(i + 1);
    }
    if (z.empty())
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    else if (z.size() == n)
    {
        cout << 3 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << n - 1 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else if (z.size() == 1)
    {
        cout << 2 << endl;
        if (z[0] == 1)
            cout << 1 << " " << 2 << "\n"
                 << 1 << " " << n - 1 << endl;
        else
            cout << z[0] - 1 << " " << z[0] << "\n"
                 << 1 << " " << n - 1 << endl;
    }
    else
    {
        if (z[0] == 1 && z.back() == n)
        {
            cout << 3 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 2 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << z[0] << " " << z.back() << endl;
            cout << 1 << " " << n - (z.back() - z[0]) << endl;
        }
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