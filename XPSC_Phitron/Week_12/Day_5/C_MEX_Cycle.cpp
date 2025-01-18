#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v;
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i % 2);
        }
        if (v[x - 1] == v[y - 1])
            v[x - 1] = 2;
    }
    else
    {
        for (int i = 1; i <= n - 1; i++)
        {
            v.push_back(i % 2);
        }
        v.insert(v.begin() + x - 1, 2);
    }
    for (auto &vl : v)
        cout << vl << " ";
    cout << endl;
}
int main()
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