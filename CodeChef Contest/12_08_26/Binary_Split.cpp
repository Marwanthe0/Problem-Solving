#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int z = count(all(s), '0'), o = count(all(s), '1');
    if (z == 0 || o == 0) {
        cout << s << endl;
        return;
    }
    map<string, int> m;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            int j = i, k = i - 1;
            string tmp;
            while (k >= 0 && s[k] == s[i - 1]) {
                tmp = s[i - 1] + tmp;
                k--;
            }
            while (j < n && s[j] == s[i]) {
                tmp.push_back(s[i]);
                j++;
            }
            m[tmp]++;
        }
    }
    cout << (m.begin())->first << endl;
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