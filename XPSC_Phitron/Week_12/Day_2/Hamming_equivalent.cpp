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
int s(int n)
{
    int x = __lg(n), count = 0;
    for (int i = x; i >= 0; i--)
    {
        if (n & (1 << i))
            count++;
    }
    return count;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        if (i == v[i])
            continue;
        if (s(i) != s(v[i]))
        {
            no;
            return;
        }
    }
    yes;
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