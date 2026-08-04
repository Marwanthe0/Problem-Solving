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
    vector<int> v(3, 0);
    cin >> v[0] >> v[1] >> v[2];
    sort(all(v));
    int count = 0;
    while (1) {
        if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) {
            cout << count << endl;
            return;
        }
        v.back()--, v.front()++;
        sort(all(v));
        count++;
    }
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