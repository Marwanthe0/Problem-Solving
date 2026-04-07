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
void marwan() {
    int k;
    cin >> k;
    int sum = 0ll;
    int count1 = 1, count2 = 1;
    vector<int> v;
    while (k) {
        int x = sqrt(1 + 8 * k);
        int y = (1 + x) / 2;
        k -= ((y) * (y - 1)) / 2;
        sum += y;
        v.push_back(y);
    }
    cout << sum << endl;
    for (auto vl : v) {
        for (int i = 0; i < vl; i++, count1++) {
            cout << count1 << " " << count2 << endl;
        }
        count2++;
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