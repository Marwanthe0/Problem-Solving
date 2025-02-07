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
vector<int> coffee(N, 0), ans(N, 0);
void marwan()
{
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        coffee[a]++, coffee[b + 1]--;
    }
    for (int i = 1; i < N; i++)
    {
        coffee[i] += coffee[i - 1];
        ans[i] += ans[i - 1];
        if (coffee[i] >= k)
        {
            ans[i]++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        // for (int j = a; j <= b; j++)
        // {
        //     cout << ans[j] << " ";
        // }
        // cout << endl;
        cout << ans[b] - ans[a - 1] << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}