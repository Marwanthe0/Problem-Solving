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
int minOperations(string s) {
    int n = s.size();
    reverse(s.begin(), s.end());
    int ans = INT_MAX;
    auto f = [&](string &t) {
        int count = 0;
        cerr << t << endl;
        int i = 0, j = (int)t.size() - 1;
        cerr << i << " " << j << endl;
        while (i < j) {
            // cerr << i << " " << j << endl;
            if (t[i] < t[j]) {
                // cerr << (s[j] - s[i], (s[i] - 'a') + ('z' - s[j]) + 2) << endl;
                count += min(t[j] - t[i], (t[i] - 'a') + ('z' - t[j]));
            } else {
                cerr << (s[i] - s[j], (s[j] - 'a') + ('z' - s[i]) + 2) << endl;
                count += min(t[i] - t[j], (t[j] - 'a') + ('z' - t[i]));
            }
            cerr << count << " " << i << " " << j << endl;
            i++, j--;
        }
        return count;
    };
    // string tt = "ab";
    // cout << f(tt) << endl;
    for (int i = 0; i < n; i++) {
        ans = min(ans, f(s));
        char c = s.back();
        s.pop_back();
        s = c + s;
        cout << s << " " << f(s) << endl;
    }
    ans = min(ans, f(s));
    return ans;
}
void marwan() {
    string s;
    cin >> s;
    cout << minOperations(s);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}
