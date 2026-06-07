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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    t.push_back(s[0]);
    for (int i = 1; i < n; i++) {
        if (s[i] != t.back() || t.size() % 2 == 0)
            t.push_back(s[i]);
    }
    if (t.size() & 1)
        t.pop_back();
    cout << s.size() - t.size() << endl;
    cout << t << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}