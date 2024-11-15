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
    vector<int> v(n + 1);
    v.push_back(INT_MIN);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int cnt = 0; cnt < 100; cnt++)
    {
        for (int i = 1; i < n; i++)
        {
            if (v[i] != i && abs(v[i] - v[i + 1]) <= 1)
                swap(v[i], v[i + 1]);
            else if (v[i] != i && i != 1 && abs(v[i] - v[i + 1]) > 1 && abs(v[i] - v[i - 1]) > 1)
            {
                no;
                return;
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] != i)
            {
                flag = false;
            }
        }
        if (flag)
        {
            yes;
            return;
        }
    }
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