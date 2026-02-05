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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int f(pair<pair<int, int>, int> &a)
{
    if (a.first.first == a.first.second && a.first.first == a.second)
        return 1;
    else if (a.first.first == a.first.second || a.first.first == a.second || a.first.second == a.second)
        return 3;
    else
        return 6;
}
void marwan()
{
    int n;
    cin >> n;
    pair < pair<int, int>, int >> ans;
    int a = 0;
    for (int i = n; i >= (n / 2); i--)
    {
        int x = i, y = (n - i) + 1;
        a += 
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