#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int dp[1005][1005];
int issum(int n, vector<int> v, int s)
{
    if (!n)
    {
        return !s;
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    if (v[n - 1] <= s)
    {
        int op1 = issum(n - 1, v, s - v[n - 1]);
        int op2 = issum(n - 1, v, s);
        return dp[n][s] = op1 + op2;
    }
    else
    {
        return dp[n][s] = issum(n - 1, v, s);
    }
}
void marwan()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int s;
    cin >> s;
    // if (issum(n, v, s))
    //     yes;
    // else
    //     no;
    cout << issum(n, v, s) << endl;
}
int main()
{
    marwan();
    return 0;
}