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
    int n, k;
    cin >> n >> k;
    if (k > n - 2) {
        minus;
        return;
    }
    string s;
    if (n & 1) {
        for (int i = 0; i < (k / 2) + 1; i++) {
            s.push_back('1');
        }
        for (int i = 0; i < ((k + 1) / 2) + 1; i++) {
            s.push_back('0');
        }
        if (s.empty())
            s.push_back('1');
        while ((int)s.size() < n) {
            s.push_back('0' + (1 - (s.back() - '0')));
        }
    } else {
        for (int i = 0; i < (k / 2) + 1; i++) {
            s.push_back('1');
        }
        for (int i = 0; i < ((k + 1) / 2) + 1; i++) {
            s.push_back('0');
        }
        if (s.empty())
            s.push_back('1');
        while ((int)s.size() < n) {
            s.push_back('0' + (1 - (s.back() - '0')));
        }
    }
    cout << s << endl;
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