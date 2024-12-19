#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, -1);
    int x = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
            v[i] = x++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == -1)
        {
            v[i] = x++;
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