#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int mn = INT_MAX, ans;
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll sum = 0, idx = 0, ans = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    ans = min(ans, sum);
    for (int i = 1; i <= n - k; i++)
    {
        sum -= v[i - 1];
        sum += v[i + k - 1];
        // cout << i << " :" << sum << " " << endl;
        if (sum < ans)
        {
            ans = sum;
            idx = i;
        }
    }
    cout << idx + 1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}