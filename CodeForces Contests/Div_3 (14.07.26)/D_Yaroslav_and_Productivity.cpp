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
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(b.begin(), b.end());
    int sum = 0ll, last = 0ll;
    for (int i = 0; i < m; i++) {
        int tsum = 0ll;

        for (int j = last; j < b[i]; j++) {
            tsum += v[j];
        }
        // cerr << tsum << endl;
        sum += abs(tsum);
        last = b[i];
    }
    for (int j = last; j < n; j++) {
        sum += v[j];
    }

    cout << sum << endl;
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