#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl;
ll p_s[10000000] = {0};
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++)
        p_s[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        p_s[i] = p_s[i - 1] + v[i];
    }
    // for (int i = 1; i <= n; i++)
    //     cout << p_s[i] << " ";
    // cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << p_s[r] - p_s[l - 1] << endl;
        }
    }
    return 0;
}