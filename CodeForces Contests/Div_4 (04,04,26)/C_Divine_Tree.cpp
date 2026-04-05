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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, m;
    cin >> n >> m;
    if (m < n || m > (n * (n + 1)) / 2) {
        minus;
        return;
    }
    vector<int> ans(n, -1);
    int last = -1;
    int x = n, k = m, z = n;
    for (int i = 0; i < n; i++, z--) {
        int y = min(x, k - (z - 1));
        k -= y;
        x = min(x, y - 1);
        ans[i] = y;
        if (y == 1) {
            last = i + 1;
            break;
        }
    }
    set<int> s(all(ans));
    for (int i = 1; i <= n; i++) {
        if (!s.count(i)) {
            ans[last++] = i;
        }
    }
    cout << ans.front() << endl;
    for (int i = 0; i < (int)(ans.size()) - 1; i++) {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
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