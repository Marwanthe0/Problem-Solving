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
    string s;
    cin >> s;
    char t = s[0];
    unordered_set<int> ind;
    ind.insert(0);
    string ans;
    ans.push_back(t);
    for (int i = 1; i < n; i++) {
        if (s[i] >= t) {
            ind.insert(i), t = s[i];
            ans.push_back(s[i]);
        }
    }
    sort(all(ans));
    string tans;
    for (int i = 0; i < n; i++) {
        if (!ind.count(i))
            tans.push_back(s[i]);
    }
    sort(all(tans));
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (ind.count(i))
            cout << ans[j++];
        else
            cout << tans[k++];
    }
    cout << endl;
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