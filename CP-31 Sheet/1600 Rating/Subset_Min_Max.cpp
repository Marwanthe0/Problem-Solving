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
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    string s;
    cin >> s;
    multiset<int, greater<int>()> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0')
            a.insert(v[i]);
        else
            b.insert(v[i]);
    }
    auto last = (--a.end());
    int ans = *(a.begin()) * (*last);
    while (1) {
        last = (--a.end());
        if (a.size() > 1 && b.size()) {
            int tans = *(a.begin()) * (*(--last));
            int tbans = *(a.begin()) * (*(b.begin()));
            if (tans - k < ans && tbans - x < ans)
                break;
            if (tans > tbans) {
                b.insert(*(--a.end()));
                a.erase(--a.end());
                ans = max(ans, tans - k);
            } else {
                a.insert(*(b.begin()));
                b.erase(b.begin());
                ans = max(ans, tbans - k);
            }
        }
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