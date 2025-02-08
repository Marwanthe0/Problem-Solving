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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> a(32, 0);
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (auto vl : v)
        {
            if (vl & (1 << i))
                count++;
        }
        a[i] = count;
    }
    // for (int i = 8; i >= 0; i--)
    //     cout << a[i] << " ";
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (auto vl : a)
        {
            if (vl > 0 && (vl % i) != 0)
                flag = false;
        }
        if (flag)
            cout << i << " ";
    }
    cout << endl;
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