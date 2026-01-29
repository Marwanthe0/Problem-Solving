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
map<int, pair<int, int>> m;
int query(int i, int j)
{
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int x;
    cin >> x;
    return x;
}
int common(int a, int b)
{
    pair<int, int> x = m[a], y = m[b];
    if (x.first == y.first || x.first == y.second)
        return x.first;
    return x.second;
}
void marwan()
{
    vector<int> v = {4, 8, 15, 16, 23, 42};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            m[v[i] * v[j]] = {v[i], v[j]};
        }
    }
    int q1 = query(0, 1);
    int q2 = query(1, 2);
    int b = common(q1, q2);
    int a = q1 / b, c = q2 / b;
    int q3 = query(3, 4);
    int q4 = query(4, 5);
    int e = common(q3, q4);
    int d = q3 / e, f = q4 / e;
    cout << "! " << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}