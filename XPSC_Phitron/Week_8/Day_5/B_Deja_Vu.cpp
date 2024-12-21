#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n), cmd(q);
    for (auto &vl : v)
        cin >> vl;
    for (auto &vl : cmd)
        cin >> vl;
    int mx = *max_element(v.begin(), v.end());
    for (int i = 0; i < q; i++)
    {
        if (mx >= (1 << cmd[i]))
        {
            for (int j = 0; j < n; j++)
            {
                if (v[j] % (1 << cmd[i]) == 0)
                {
                    v[j] += (1 << (cmd[i] - 1));
                }
                mx = max(mx, v[j]);
            }
        }
    }
    for (auto vl : v)
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