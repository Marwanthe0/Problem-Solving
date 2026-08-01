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
    string s;
    cin >> s;
    string t;
    bool flag1 = true, flag = true;
    for (int i = 0; i < (int)(s.size()); i++) {
        if (flag1 && s[i] == '0') {
            flag1 = false;
            continue;
        }
        if (flag && s[i] == '1') {
            flag = false;
            continue;
        } else
            cout << s[i];
    }
    cout << endl;
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