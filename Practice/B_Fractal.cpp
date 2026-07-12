#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<string> a, b;
int n, k;
vector<string> f(int i, int j, vector<string> cur, int t) {
    vector<string> ans(pow(n, t), string());
    for (int i = 0; i < cur.size(); i++) {
        for (int j = 0; j < cur[i].size(); j++) {
            if()
        }
    }
}
void marwan() {
    cin >> n >> k;
    a.assign(n, string());
    b.assign(n, string());
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        string temp;
        temp.assign(n, '*');
        b[i] = temp;
    }
    vector<string> ans = f(0, 0, a, k);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}