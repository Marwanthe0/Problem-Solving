#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Alice" << endl
#define no cout << "Bob" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
bool ans(string &s) {
    int n = s.size();
    int last = 0;
    int count = 0;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            count++;
        } else {
            last += count;
            if (count > 0 && count % 2 != 0) {
                flag = true;
            }
        }
    }
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones++;
        } else {
            if (ones > 0 && ones % 2 != 0) {
                flag = true;
            }
        }
    }
    if (last % 2 != 0 || flag) {
        return true;
    }
    return false;
}
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] - '0')
            t.push_back('0');
        else
            t.push_back('1');
    if (ans(s) || ans(t)) {
        yes;
    } else
        no;
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