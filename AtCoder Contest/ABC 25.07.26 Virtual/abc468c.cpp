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
vector<int> fact;
int f(vector<int> &a) {
    int n = a.size();
    vector<int> v(all(a));
    int ans = 0ll;
    set<int> s;
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        int x = v[i];
        for (auto vl : s) {
            // cerr << vl << " ";
            if (v[i] > vl)
                x--;
        }
        // cerr << endl;
        // cerr << j << " " << x - 1 << endl;
        if (j >= 0)
            ans += fact[j] * 1ll * (x - 1);
        s.insert(v[i]);
    }
    // cerr << endl;
    return ans;
}
void marwan() {
    fact.assign(11, 0ll);
    fact[0] = 1;
    for (int i = 1; i <= 10; i++)
        fact[i] = i * 1ll * fact[i - 1];
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    // cout << f(a) << " " << f(b) << endl;
    // return;
    if (f(b) <= f(a))
        cout << 0 << endl;
    else
        cout << (f(b) - f(a)) - 1 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}