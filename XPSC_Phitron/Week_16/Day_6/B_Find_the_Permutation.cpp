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
    vector<string> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                if (v[i][j] == '1')
                    count++;
            }
            else if (j > i)
            {
                if (v[i][j] == '0')
                    count++;
            }
        }
        // cout << count << " ";
        ans[count] = i + 1;
    }
    for (auto vl : ans)
        cout << vl << " ";
    cout
        << endl;
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