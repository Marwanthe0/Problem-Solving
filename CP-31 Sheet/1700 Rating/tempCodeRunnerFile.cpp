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
int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
void marwan() {
    int l = 1, r = 999, count = 0;
    while (l <= r) {
        int mid1 = (l + r) / 3, mid2 = 2 * ((l + r) / 3);
        if (r - l + 1 <= 3) {
            int tx = ask(mid1, mid1 + 1);
            if (tx == mid1 * (mid1 + 1)) {
                cout << "! " << mid2 << endl;
                cout.flush();
                return;
            } else if (tx == mid1 * (mid1 + 2)) {
                cout << "! " << mid1 + 1 << endl;
                cout.flush();
                return;
            } else {
                cout << "! " << mid1 << endl;
                cout.flush();
                return;
            }
        }
        int x = ask(mid1, mid2);
        if (x == -1 || count > 7) {
            minus;
            cout.flush();
            return;
        }
        if (x == mid1 * mid2) {
            l = mid2 + 1;
        } else if (x == mid1 * (mid2 + 1)) {
            l = mid1, r = mid2;
        } else
            r = mid1;
        count++;
    }
    cout << "! " << l << endl;
    cout.flush();
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