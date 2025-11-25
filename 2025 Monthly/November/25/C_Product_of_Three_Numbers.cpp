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
    set<int> s;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            s.insert(i);
            if (s.size() >= 3)
            {
                yes;
                for (auto vl : s)
                    cout << vl << " ";
                cout << endl;
                return;
            }
        }
    }
    no;
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