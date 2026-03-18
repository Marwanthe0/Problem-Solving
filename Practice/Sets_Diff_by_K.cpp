#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i]) {
            s.insert(i + 1);
        }
    }
    if (s.empty()) {
        no;
        return;
    }
    int last = INT_MAX, count = k, count2 = k, slast = INT_MIN;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        if (v[i]) {
            if (last != INT_MAX && i - last <= k) {
                no;
                return;
            }
            last = i, count = k;
        } else if (i - last > k) {
            count--;
        }
        if (count < 0) {
            no;
            return;
        }
        if (v[j]) {
            if (slast != INT_MIN && slast - j <= k) {
                no;
                return;
            }
            slast = j, count2 = k;
        } else if (slast - j > k) {
            count2--;
        }
        if (count2 < 0) {
            no;
            return;
        }
    }
    if (count != k || count2 != k) {
        no;
        return;
    }
    yes;
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