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
vector<int> vis(N + 1, 0);
vector<vector<int>> divs(N + 1, vector<int>());
void pre() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), done(k + 1, 0);
    int mx = 0;
    for (auto &vl : v) {
        cin >> vl;
        vis[vl]++;
        mx = max(mx, vl);
    }
    sort(all(v));
    int count = 0;
    for (auto vl : v) {
        int x = vl;
        for (auto val : divs[vl]) {
            if (val > k)
                break;
            if (!done[val])
                count++;
            done[val]++;
        }
    }
    if (count != k) {
        minus;
        return;
    }
    int l = 0, r = n - 1;
    while (l <= r) {
        
    }
    cout << v[end] - v[start] << endl;
    // for (auto vl : v)
    //     vis[vl] = 0;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}