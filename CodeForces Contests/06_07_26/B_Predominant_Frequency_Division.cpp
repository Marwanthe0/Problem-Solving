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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> pf(n + 1, 0);
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1)
            one++;
        else if (v[i] == 2)
            two++;
        else
            three++;
        if (one >= two + three) {
            pf[i] = 1;
        }
    }
    one = 0, two = 0, three = 0;
    int mx = 0;
    for (int i = n - 2; i > 0; i--) {
        if (v[i] == 1)
            one++;
        else if (v[i] == 2)
            two++;
        else
            three++;
        if ((one + two >= (three - mx)) && pf[i - 1]) {
            yes;
            return;
        }
        mx = max(mx, three - (one + two));
    }
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