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
    int l = 1, r = n * n;
    bool flag = true;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
    {
        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    v[i][j] = l++;
                }
                else
                    v[i][j] = r--;
            }
            flag = false;
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (i % 2)
                {
                    v[i][j] = l++;
                }
                else
                    v[i][j] = r--;
            }
            flag = true;
        }
    }
    for (auto vc : v)
    {
        for (auto vl : vc)
            cout << vl << " ";
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