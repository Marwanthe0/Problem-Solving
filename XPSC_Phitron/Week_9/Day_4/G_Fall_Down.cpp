#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        int star = 0;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == '*')
                star++;
            if (i == n - 1 && a[i][j] != 'o')
            {
                int temp = i;
                while (temp >= last)
                {
                    if (a[temp][j] == 'o')
                        break;
                    if (star > 0)
                        a[temp][j] = '*';
                    else
                        a[temp][j] = '.';
                    temp--, star = max(0, star - 1);
                }
                last = i;
            }
            else if (a[i][j] == 'o')
            {
                int temp = i - 1;
                while (temp >= last)
                {
                    if (a[temp][j] == 'o')
                        break;
                    if (star > 0)
                        a[temp][j] = '*';
                    else
                        a[temp][j] = '.';
                    temp--, star = max(0, star - 1);
                }
                last = i;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j];
        cout << endl;
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