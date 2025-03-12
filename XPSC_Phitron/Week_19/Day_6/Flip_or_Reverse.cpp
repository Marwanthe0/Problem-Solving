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
    string a, b;
    cin >> a >> b;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            continue;
        else
        {
            int j = i;
            while (a[j] != b[j])
                j++;
            v.push_back({1, i + 1, j});
            i = j - 1;
        }
    }
    cout << v.size() << endl;
    for (auto [x, y, z] : v)
        cout << x << " " << y << " " << z << endl;
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