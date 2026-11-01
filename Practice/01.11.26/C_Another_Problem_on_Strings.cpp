#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int k, n;
    cin >> k;
    string s;
    cin >> s;
    n = s.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = s[i] - '0';
    map<int, pair<int, int>> m;
    m[0] = {-1, -1};
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (sum >= k && m.count(sum - k)) {
            int prev = sum - k;
            ans += (m[prev].second - m[prev].first + 1);
        }

        if (!m.count(sum))
            m[sum] = {i, i};
        else
            m[sum].second = i;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}