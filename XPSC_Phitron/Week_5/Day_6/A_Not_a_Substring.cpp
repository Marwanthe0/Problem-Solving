#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s;
    cin >> s;
    int x = 0, y = 0, ans = 0, n = s.size();
    if (n == 2 && s == "()")
    {
        no;
        return;
    }
    yes;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            x++;
            ans = max(ans, x);
        }
        else
            x = 0;
    }
    if (ans)
    {
        for (int i = 0; i < n * 2; i++)
        {
            if (i % 2)
                cout << ')';
            else
                cout << '(';
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < (n * 2); i++)
        {
            if (i < n)
                cout << '(';
            else
                cout << ')';
        }
        cout << endl;
    }
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