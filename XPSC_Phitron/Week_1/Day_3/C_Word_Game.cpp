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
    string s[3][n];
    map<string, int> m;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string cp;
            cin >> cp;
            s[i][j] = cp;
            m[cp]++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        ll count = 0;
        for (int j = 0; j < n; j++)
        {
            if (m[s[i][j]] == 3)
            {
            }
            else if (m[s[i][j]] == 2)
                count++;
            else if (m[s[i][j]] == 1)
                count += 3;
        }
        cout << count << " ";
    }
    cout << endl;
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