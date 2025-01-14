#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> vis(5009, 0), x = v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5000; j++)
        {
            if (vis[j] == 0 && j != v[i])
            {
                v[i] = j;
                vis[j] = 1;
                break;
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (v[i] > n)
        {
            v[i]--;
            swap(v[i], v[i - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
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