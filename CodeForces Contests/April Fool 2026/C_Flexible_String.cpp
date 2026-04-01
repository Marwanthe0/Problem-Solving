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
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    set<char> s;
    for (auto c : a)
        s.insert(c);
    map<char, int> mt;
    string st = a;
    make_unique(st);
    int cnt = 0, ans = 0;
    for (auto c : st) {
        mt[c] = cnt++;
    }
    int mask = 1 << (s.size());
    for (int j = 0; j < mask; j++) {
        if (__builtin_popcount(j) > k)
            continue;
        int count = 0, tans = 0ll;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                count++;
            else if (1 & (j >> mt[a[i]]))
                count++;
            else {
                tans += (count * (count + 1)) / 2;
                count = 0;
            }
        }
        tans += (count * (count + 1)) / 2;
        ans = max(ans, tans);
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