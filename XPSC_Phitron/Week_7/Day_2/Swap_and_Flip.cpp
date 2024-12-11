#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int s1 = 0, s0 = 0, t1 = 0, t0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            s1++;
        else if (s[i] == '0')
            s0++;
        if (t[i] == '1')
            t1++;
        else if (t[i] == '0')
            t0++;
    }
    if ((max(s1, t1) - min(s1, t1)) % 2 == 0)
        yes;
    else
        no;
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