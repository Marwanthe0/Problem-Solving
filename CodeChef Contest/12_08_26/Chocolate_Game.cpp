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
    vector<int> v(n), odds;
    int sum = 0;
    int ev = 0, odd = 0;
    for (auto &vl : v) {
        cin >> vl;
        sum += vl;
        if (vl & 1)
            odd++;
        else
            ev++;
        if (vl & 1)
            odds.push_back(vl);
    }
    int alice = 0, bob = 0;
    for (auto vl : v) {
        if (vl % 2 == 0) {
            if (sum & 1)
                bob += vl;
            else
                alice += vl;
        }
    }
    // cerr << sum << endl;
    if (sum % 2 == 0) {
        for (auto &vl : odds) {
            alice += vl - 1;
            vl = 1;
        }
        alice += (odd + 1) / 2;
    } else {
        for (auto &vl : odds) {
            bob += vl - 1;
            vl = 1;
        }
        alice += (odd / 2);
    }
    cout << alice << endl;
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