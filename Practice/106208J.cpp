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
vector<vector<int>> base = {{1, 0}, {0, 1}};

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> c(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
};
vector<vector<int>> binexp(vector<vector<int>> &a, int b) {
    vector<vector<int>> ans = base;
    vector<vector<int>> x = a;
    while (b) {
        if (b & 1) {
            ans = mul(ans, x);
        }
        x = mul(x, x);
        b >>= 1;
    }
    return ans;
}
vector<pair<int, int>> fib;
void pre() {
    fib.assign(N + 1, {0, 0});
    fib[0] = {1, 0};
    fib[1] = {0, 1};
    for (int i = 2; i <= N; i++) {
        fib[i].first = fib[i - 1].first % M + fib[i - 2].first % M;
        fib[i].second = fib[i - 1].second % M + fib[i - 2].second % M;
    }
    // for (int i = 1; i <= N; i++) {
    //     fib[i].first += fib[i - 1].first;
    //     fib[i].first %= M;

    //     fib[i].second += fib[i - 1].second;
    //     fib[i].second %= M;
    // }
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int q;
    cin >> q;
    vector<int> query(q);
    for (auto &vl : query)
        cin >> vl;
    for (auto vl : query) {
        vl *= 2;
        int x = fib[vl + 1].first, y = fib[vl + 1].second;
        cout << x << " " << y << endl;
        int tans = 0ll;
        for (int i = 1; i < n; i++) {
            int a = v[i], b = v[i - 1];
            if (a > b)
                swap(a, b);
            cout << x * a + y * b << " ";
            tans = max(tans, ((x * 1ll * a % M) + (y * 1ll * b) % M) % M);
        }
        cout << tans << endl;
        cout << endl;
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    // vector<vector<int>> a = {{1, 1}, {1, 0}};
    // for (int i = 1; i <= 20; i++) {
    //     vector<vector<int>> temp = binexp(a, i);
    //     for (auto &vl : temp) {
    //         for (auto &val : vl)
    //             cout << val << " ";
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i <= 10; i++)
        cerr << fib[i].first << " " << fib[i].second << endl;
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}