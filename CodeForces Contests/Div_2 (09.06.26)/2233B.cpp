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
    vector<int> v(4 * n, -1);
    v[0] = n;
    for (int i = 1; i <= n; i++) {
        set<int> dif;
        int last = INT_MIN;
        int count = 0;
        for (int j = 0; j <= 4 * n; j++) {
            if (v[j] == -1) {
                if (dif.count(j - last) == 0) {
                    v[j] = i;
                    dif.insert(j - last);
                    last = j;
                    count++;
                }
            }
            if (count >= 4)
                break;
        }
    }
    for (auto vl : v)
        cout << vl << " ";
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