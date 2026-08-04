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
    vector<int> v(n);
    map<int, int> m;
    int sum = 0ll;
    for (auto &vl : v) {
        cin >> vl;
        if (vl & 1)
            m[vl]++;
        sum += vl;
    }
    vector<int> t;
    for (auto [_, y] : m)
        t.push_back(y);
    sort(all(t));
    reverse(all(t));
    int a = 0ll, b = 0ll;
    for (int i = 0; i < (int)t.size(); i++) {
        if (i & 1)
            b += t[i];
        else
            a += t[i];
    }
    int rem = sum - (a + b);
    rem /= 2;
    cout << a + rem << " " << b + rem << endl;
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