#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    map<char, multiset<int>> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map<char, int> tm;
        for (auto &c : s)
            tm[c]++;
        for (auto &[c, y] : tm) {
            m[c].insert(y);
        }
    }
    string ans;
    for (auto &[c, y] : m) {
        if (y.size() >= n) {
            int x = *y.begin();
            while (x--)
                ans.push_back(c);
        }
    }
    if (ans.empty()) {
        cout << "no such string" << endl;
    }
    sort(all(ans));
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}