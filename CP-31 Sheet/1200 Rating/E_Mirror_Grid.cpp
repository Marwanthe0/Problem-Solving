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
    vector<string> temp(n);
    for (auto &vl : temp)
        cin >> vl;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            v[i][j] = temp[i - 1][j - 1] - '0';
            cerr << v[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
    int count = 0;
    for (int i = 1; i <= (n / 2); i++)
    {
        for (int j = 1; j <= ((n / 2) + (n % 2)); j++)
        {
            int a = v[i][j], b = v[j][(n - i) + 1], c = v[(n - i) + 1][(n - j) + 1], d = v[(n - j) + 1][i];
            int sum = a + b + c + d;
            // cerr << sum << " ";
            sum %= 4;
            if (sum == 3)
                count += 1;
            else
                count += sum;
        }
        // cerr << endl;
    }
    // cerr << endl;
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