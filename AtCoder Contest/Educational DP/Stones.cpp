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
int n;
vector<int> v;
bool dp[101][100001][2], vis[101][100001][2];
bool f(int i, int k, bool taro) {
    if (i < 0) {
        return !taro;
    }
    if (vis[i][k][taro]) {
        return dp[i][k][taro];
    }
    if (taro) {
        bool ans = false;
        if (v[i] <= k) {
            ans |= f(n - 1, k - v[i], !taro);
        }
        ans |= f(i - 1, k, taro);
        vis[i][k][taro] = true;
        return dp[i][k][taro] = ans;
    } else {
        bool ans = true;
        if (v[i] <= k)
            ans &= f(n - 1, k - v[i], !taro);
        ans &= f(i - 1, k, taro);
        vis[i][k][taro] = true;
        return dp[i][k][taro] = ans;
    }
}
void marwan() {
    int k;
    cin >> n >> k;
    v.resize(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    memset(vis, false, sizeof(vis));
    bool ans = f(n - 1, k, 1);
    if (ans)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}