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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    map<pair<int, pair<int, int>>, int> ms;
    int ans = 0;
    for (int i = 2; i < n; i++) {
        pair<int, pair<int, int>> x;
        x.first = v[i - 2], x.second.first = v[i - 1], x.second.second = -1;
        ans += ms[{x.first, {x.second.first, x.second.second}}];
        x.second.second = v[i], x.second.first = -1;
        ans += ms[{x.first, {x.second.first, x.second.second}}];
        x.second.first = v[i - 1], x.first = -1;
        ans += ms[{x.first, {x.second.first, x.second.second}}];
        x.first = v[i - 2];
        ans -= 3 * ms[{x.first, {x.second.first, x.second.second}}];

        x.first = v[i - 2], x.second.first = v[i - 1], x.second.second = -1;
        ms[{x.first, {x.second.first, x.second.second}}]++;
        x.second.second = v[i], x.second.first = -1;
        ms[{x.first, {x.second.first, x.second.second}}]++;
        x.second.first = v[i - 1], x.first = -1;
        ms[{x.first, {x.second.first, x.second.second}}]++;
        x.first = v[i - 2];
        ms[{x.first, {x.second.first, x.second.second}}]++;
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