#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
void marwan(int cs) {
    string a, b;
    cin >> a >> b;
    string t;
    vector<int> x, y;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '.') {
            x.push_back(stoi(t));
            t.clear();
        } else
            t.push_back(a[i]);
    }
    x.push_back(stoi(t));
    int cnt = 7, val = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '.') {
            y.push_back(val);
            val = 0, cnt = 7;
        } else {
            if (b[i] == '1') {
                val += (1ll << cnt);
            }
            cnt--;
        }
    }
    y.push_back(val);
    if (x == y) {
        yes;
    } else
        no;
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