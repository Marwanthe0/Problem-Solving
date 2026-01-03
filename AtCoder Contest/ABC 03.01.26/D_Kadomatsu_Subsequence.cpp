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
    vector<int> v(n), a, b, c;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % 3 == 0)
            a.push_back(i);
        if (x % 5 == 0)
            b.push_back(i);
        if (x % 7 == 0)
            c.push_back(i);
    }
    for (auto vl : a)
        cout << vl;
    cout << endl;
    for (auto vl : b)
        cout << vl;
    cout << endl;
    for (auto vl : c)
        cout << vl;
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}