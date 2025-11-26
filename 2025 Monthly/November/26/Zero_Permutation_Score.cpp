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
    int n, count = 0;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 1; i < n; i += 2)
    {
        v[i] = 1;
        for (int j = 1; j < n; j++)
            if (v[j] == v[j - 1] && v[j] == 0)
                count++;
    }
    cout << count << endl;
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