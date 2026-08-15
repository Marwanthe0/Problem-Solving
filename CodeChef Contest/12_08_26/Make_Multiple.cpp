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
    int n;
    cin >> n;
    int ans = n % 3;
    if (ans == 0)
        cout << 0 << endl;
    else if (ans == 2)
        cout << 1 << endl;
    else {
        for (int i = n + 1;; i++) {
            if (i % 5 == 0) {
                if (i % 3 == 0) {
                    cout << 1 << endl;
                    return;
                }
                break;
            }
        }
        cout << 2 << endl;
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