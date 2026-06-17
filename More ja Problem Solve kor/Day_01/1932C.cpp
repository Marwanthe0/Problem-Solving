#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e4
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
vector<vector<int>> divs(N + 1);
// void pre() {
//     for (int i = 1; i <= N; i++) {
//         for (int j = i; j <= N; j += i)
//             divs[j].push_back(i);
//     }
// }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = ans * 1ll * a;
        a = a * 1ll * a;
        b /= 2ll;
    }
    return ans;
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    for (auto c : s) {
        int x;
        if (l >= r)
            break;
        if (c == 'L') {
            x = v[l];
            l++;
        } else {
            x = v[r];
            r--;
        }
    }
    s.pop_back();
    reverse(all(s));
    vector<int> uttor;
    uttor.push_back(v[l] % k);
    int ans = v[l];
    for (auto c : s) {
        if (c == 'L') {
            l--;
            ans = (ans * 1ll * v[l]) % k;
        } else {
            r++;
            ans = (ans * 1ll * v[r]) % k;
        }
        uttor.push_back(ans);
    }
    reverse(all(uttor));
    for (auto vl : uttor)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // pre();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}