#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int f(char c) { return c - '0'; }
void marwan()
{
    string s;
    cin >> s;
    ll n = s.size();
    if (f(s[0]) >= 5)
    {
        cout << 1;
        for (int i = 0; i < n; i++)
            cout << 0;
        cout << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (f(s[i]) >= 5)
        {
            int x = i - 1;
            while (x >= 0 && f(s[x]) >= 5)
            {
                x--;
            }
            while (x > 0 && s[x] == '4')
            {
                x--;
            }
            s[x]++;
            x++;
            while (x < n)
            {
                s[x++] = '0';
            }
            if (s[0] == '5')
            {
                s[0] = '0';
                s = '1' + s;
            }
            i = x;
        }
    }
    cout << s << endl;
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