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
    string s;
    cin >> s;
    if ((n & 1))
    {
        int count = 0;
        for (int i = 0; i < n / 2; i++)
            if (s[i] == '0')
                count++;
        if (count % 2 == 0)
        {
            cout << "DRAW" << endl;
        }
        else
        {
            if (s[n / 2] == '0')
                cout << "ALICE" << endl;
            else
                cout << "BOB" << endl;
        }
    }
    else
    {
        int count = 0;
        for (int i = 0; i < n / 2; i++)
            if (s[i] == '0')
                count++;
        if (count & 1)
            cout << "BOB" << endl;
        else
            cout << "ALICE" << endl;
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