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
    if (n == 1) {
        cout << 1 << endl;
        return;
    } else if (n == 2) {
        minus;
        return;
    }
    vector<int> ans = {2, 4, 6};
    int sum = 12;
    for (int i = n - 3; i > 0; i--) {
        ans.push_back(sum);
        sum += sum;
    }
    cout << ans.size() << endl;
    int tsum = accumulate(all(ans), 0ll);
    for (auto vl : ans) {
        cout << vl << " ";
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