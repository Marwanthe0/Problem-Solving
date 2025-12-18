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
vector<int> dgs(int n)
{
    vector<int> v;
    while (n)
    {
        if (n % 10)
            v.push_back(n % 10);
        n /= 10;
    }
    return v;
}
void marwan()
{
    int n;
    cin >> n;
    for (int i = n;; i++)
    {
        vector<int> digits = dgs(i);
        bool flag = true;
        for (auto vl : digits)
        {
            if (i % vl)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << i << endl;
            return;
        }
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