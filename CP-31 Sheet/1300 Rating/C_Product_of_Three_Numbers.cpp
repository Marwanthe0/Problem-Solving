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
int pw(int a, int b)
{
    if (b == 0)
        return 1;
    return pw(a, b - 1) * a;
}
void marwan()
{
    int n, count = 0;
    cin >> n;
    vector<int> ans;
    map<int, int> m;
    for (int i = 2; i * i <= n; i++)
    {
        if ((n % i) == 0)
        {
            n /= i;
            m[i]++;
            count++;
            if (count == 2)
            {
                m[n]++;
                n = 0;
            }
        }
    }
    if (m.size() != 3)
    {
        no;
        return;
    }
    else
    {
        yes;
        for (auto vl : m)
            cout << vl.first << " ";
        cout << endl;
    }
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