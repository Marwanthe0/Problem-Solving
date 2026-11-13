#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> fact;
void marwan(int cs) {
    string s;
    int k;
    cin >> s;
    cin >> k;
    int n = s.size();
    int perm = fact[n];
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    for (auto [x, y] : m)
        perm /= fact[y];
    if (k > perm) {
        cout << "Impossible" << endl;
        return;
    }
    string ans;
    for (int i = 0; i < n; i++) {
        for (auto [x, y] : m) {
            if (y <= 0)
                continue;
            int rem = fact[n - (i + 1)];
            char c = x;
            for (auto [i, j] : m) {
                if (c == i)
                    j--;
                rem /= fact[j];
            }
            
            if (k <= rem) {
                ans.push_back(c);
                m[c]--;
                break;
            } else {
                k -= rem;
            }
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact.assign(21, 0);
    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = fact[i - 1] * 1LL * i;
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}