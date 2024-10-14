#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
            count++;
        else
            break;
    }
    int ans = n + m;
    if (count)
    {
        ans -= (count - 1);
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}