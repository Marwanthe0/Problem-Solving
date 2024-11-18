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
    int a = s[0] - '0', b = s[2] - '0';
    char op = s[1];
    if (op == '>')
    {
        if (a < b)
        {
            s[1] = '<';
        }
        else if (a == b)
            s[1] = '=';
    }
    else if (op == '<')
    {
        if (a > b)
            s[1] = '>';
        else if (a == b)
            s[1] = '=';
    }
    else
    {
        if (a != b)
        {
            if (a > b)
                s[1] = '>';
            else
                s[1] = '<';
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