#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 6e6
#define endl "\n"
#define all(v) v.begin(), v.end()

vector<int> primes;
vector<char> vis(N + 1, false);

void solve_case()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    sort(all(v), greater<int>());
    int sum = 0ll, ans = 0ll;
    for (int i = 0; i < n; i++)
    {
        sum += v[i] - 2ll;
        if (sum >= primes[i] - 2)
            sum -= primes[i] - 2ll, ans++;
        else
            break;
    }
    cout << n - ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i <= N; ++i)
    {
        if (!vis[i])
        {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j <= N; j += i)
                vis[(int)j] = true;
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve_case();
    return 0;
}
