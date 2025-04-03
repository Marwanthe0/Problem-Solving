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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count = 0;
    if (s.back() == '1')
        count++;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '1')
            count++;
        else if (s[i + 1] == '1' && k > 0)
            k--, s[i] = '1', count++;
    }
    cout << count << endl;
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