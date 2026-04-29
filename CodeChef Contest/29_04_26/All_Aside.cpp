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
char flip(char c) {
    if (c == '1')
        return '0';
    else
        return '1';
}
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = n - 1;
    int count = 0;
    while (i > 0) {
        if (s[i] != s[i - 1]) {
            count++;
        }
        i--;
    }
    string t;
    int ts = 1;
    if (s[0] == '1')
        count++;
    while (count--) {
        t.push_back(ts + '0');
        ts = 1 - ts;
    }
    while (t.size() < n)
        t = "0" + t;
    cout << t << endl;
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