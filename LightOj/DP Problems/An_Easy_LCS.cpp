#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
string a, b;
int n, m;
vector<vector<string>> dp;
vector<vector<bool>> tdp;
string ans;
string best(string a, string b) {
    if (a.size() == b.size()) {
        if (a < b)
            return a;
        else
            return b;
    }
    if (a.size() > b.size())
        return a;
    return b;
}

string f(int i, int j) {
    if (i == n || j == m)
        return "";
    if (tdp[i][j])
        return dp[i][j];
    string ans = best(f(i + 1, j), f(i, j + 1));
    if (a[i] == b[j]) {
        ans = best(ans, a[i] + f(i + 1, j + 1));
    }
    tdp[i][j] = 1;
    return dp[i][j] = ans;
}
void marwan(int cs) {
    ans.clear();
    cin >> a >> b;
    n = a.size(), m = b.size();
    dp.assign(n + 1, vector<string>(m + 1, ""));
    tdp.assign(n + 1, vector<bool>(m + 1, 0));
    string lcs = f(0, 0);
    if (!lcs.size()) {
        cout << ":(";
        if (cs)
            cout << endl;
        return;
    }
    cout << lcs;
    if (cs)
        cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(t - i);
    }
    return 0;
}