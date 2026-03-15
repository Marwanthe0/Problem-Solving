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
void marwan() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v, a;
    for (int i = 0; i < n; i++) {
        v.push_back(s[i] - '0');
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += v[j];
            // if (sum) {
            a.push_back(sum);
            m[sum]++;
            // }
        }
    }
    sort(all(a));
    int ans = 0ll;
    int sz = a.size();
    for (int i = 0; i < sz; i++) {
        // cerr << a[i] << " ";
        if (k && a[i] == 0)
            continue;
        if (k == 0) {
            if (a[i] == 0)
                ans += sz;
            else
                ans += m[0];
        } else if ((k % a[i]) == 0)
            ans += m[k / a[i]];
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}