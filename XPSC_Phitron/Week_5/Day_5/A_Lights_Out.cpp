#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int n = 3;
vector<pair<int, int>> path = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}
int toggle(int n) { return !n; }
void marwan()
{
    int a[n][n];
    int ans[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            ans[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2)
            {
                ans[i][j] = 1 - ans[i][j];
                for (int k = 0; k < 4; k++)
                {
                    int x = i + path[k].first;
                    int y = j + path[k].second;
                    if (valid(x, y))
                    {
                        ans[x][y] = 1 - ans[x][y];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}