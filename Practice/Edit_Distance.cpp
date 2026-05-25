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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> prev(m + 1, INT_MAX), current(m + 1, INT_MAX);
    // dp[i][j] = minimum move to make s[0...i] = t[0...j]
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // Base Case
            if (i == 0 || j == 0) {
                if (i == 0) {
                    current[j] = j;
                }
                if (j == 0)
                    current[j] = i;
                continue;
            }
            if (s[i - 1] == t[j - 1]) { // ith and jth character are equal [no need to change]
                current[j] = prev[j - 1];
                continue;
            }
            current[j] = min({
                current[j],
                prev[j - 1] + 1,   // Replacing ith character with jth character
                prev[j] + 1,       // deleting ith character in string s
                current[j - 1] + 1 // deleting jth character in string t
            });
        }
        prev = current;
        for (int j = 0; j <= m; j++)
            current[j] = INT_MAX;
    }
    cout << prev[m] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}
