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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (abs(v[i] - v[i - 1]) == 5 || abs(v[i] - v[i - 1]) == 7)
        {
            continue;
        }
        else
            flag = false;
    }
    if (flag)
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