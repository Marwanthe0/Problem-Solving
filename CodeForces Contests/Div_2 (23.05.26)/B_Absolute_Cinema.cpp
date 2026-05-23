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
    int n;
    cin >> n;
    vector<int> a(n), b(n), v;
    for (auto &vl : a) {
        cin >> vl;
        v.push_back(vl);
    }
    for (auto &vl : b) {
        cin >> vl;
        v.push_back(vl);
    }
    int sum = 0ll;
    for (int i = 0; i < n; i++) {
        sum += max(a[i], b[i]);
        if (a[i] > b[i])
            a[i] = INT_MIN;
        else
            b[i] = INT_MIN;
    }
    sum += max(*max_element(all(a)), *max_element(all(b)));
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