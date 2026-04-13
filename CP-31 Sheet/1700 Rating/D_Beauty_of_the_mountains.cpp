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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    int sum = 0ll, sum2 = 0ll;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                sum += v[i][j];
            } else
                sum -= v[i][j];
        }
    }
    sum = abs(sum);
    cerr << sum << endl;
    if (!sum) {
        yes;
        return;
    }
    int count1 = 0, count2 = 0;
    for (int i = 0; i <= n - k; i++) {
        int ki = i + k;
        for (int j = 0; j <= m - k; j++) {
            int kj = j + k;
            count1 = 0, count2 = 0;
            for (int x = i; x < ki; x++) {
                for (int y = j; y < kj; y++) {
                    if (a[x][y] == '1')
                        count1++;
                    else
                        count2++;
                }
            }
            if (abs(count2 - count1) && (sum % abs(count2 - count1) == 0)) {
                cerr << sum << " " << i << " " << j << " " << count2 << ":" << count1 << endl;
                yes;
                return;
            }
        }
    }
    no;
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