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
bool check(int n, int m, vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    while (i < n) {
        if (a[i] >= b[j])
            j++;
        if (j == m)
            return true;
        i++;
    }
    return false;
}
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    if (check(n, m, a, b)) {
        cout << 0 << endl;
        return;
    }
    vector<int> t(all(b));
    make_unique(t);
    int l = 0, r = t.size() - 1, ans = -1;

    auto ok = [&](int mid) {
        int i = 0, j = 0, flag = false;
        while (i < n) {
            if (flag == false && b[j] == mid) {
                j++;
                flag = true;
                if (j == m)
                    return true;
                continue;
            }
            if (a[i] >= b[j])
                j++;
            if (j == m)
                return true;
            i++;
        }
        if (flag == false && b[j] == mid) {
            j++;
            if (j == m)
                return true;
        }
        return false;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2;
        bool kk = ok(t[mid]);
        if (kk) {
            ans = t[mid], r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << endl;
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