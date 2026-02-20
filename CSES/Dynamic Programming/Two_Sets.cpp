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
    int sum = (n * (n + 1)) / 2;
    if (sum & 1)
    {
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}