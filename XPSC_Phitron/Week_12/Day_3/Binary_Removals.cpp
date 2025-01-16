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
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    int z = 0, o = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            z++, count += z * o;
        else
            o++;
    }
    if (count <= x && count % k == 0)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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