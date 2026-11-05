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
string a, b;
int n;
char nxt(char c) {
    if (c == 'z')
        return 'a';
    else
        return ++c;
}
char prev(char c) {
    if (c == 'a')
        return 'z';
    else
        return --c;
}
int dist(char a, char b) {
    if (a < b)
        swap(a, b);
    return min(a - b, ('z' - a + 1) + (b - 'a'));
}
void marwan(int cs) {
    cin >> a;
    cin >> b;
    cin >> n;
    set<string> st;
    for (int i = 0; i < n; i++) {
        string x, y, z;
        cin >> x >> y >> z;
        for (auto c1 : x) {
            for (auto c2 : y) {
                for (auto c3 : z) {
                    string t;
                    t.push_back(c1);
                    t.push_back(c2);
                    t.push_back(c3);
                    st.insert(t);
                }
            }
        }
    }
    if (st.count(a) || st.count(b)) {
        minus;
        return;
    }
    int ans = dist(a[0], b[0]) + dist(a[1], b[1]) + dist(a[2], b[2]);

    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}