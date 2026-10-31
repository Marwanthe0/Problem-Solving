#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, m;
int f(int i, int j, int sum) {
    if (j == 0)
        return sum == 0;
    if (sum == 0 || i == 0)
        return 0;
    int ans = 0ll;
    for (int k = i; k >= 1; k--) {
        ans += f(k, j - 1, sum + (i % k));
    }
    return ans;
}
void marwan() {
    cin >> n >> m;
    f(m + 2, n, m);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}