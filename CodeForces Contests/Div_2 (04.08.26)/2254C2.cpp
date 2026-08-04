#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
void marwan() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int odd = 0, even = 0, odds = 0, evens = 0;
    vector<int> ao, ae, bo, be;
    for (int i = 0; i < n; i++) {
        if (b[i] == '1') {
            if (i & 1) {
                bo.push_back(i);
                odd++;
            } else {
                even++;
                be.push_back(i);
            }
        }
        if (a[i] == '1') {
            if (i & 1) {
                odds++;
                ao.push_back(i);
            } else {
                evens++;
                ae.push_back(i);
            }
        }
    }
    if (odds == odd && evens == even) {
        sort(all(ae));
        sort(all(be));
        sort(all(ao));
        sort(all(bo));
        int xs = 0ll;
        for (int i = 0; i < ao.size(); i++) {
            xs += abs(ao[i] - bo[i]) / 2;
        }
        for (int i = 0; i < ae.size(); i++) {
            xs += abs(ae[i] - be[i]) / 2;
        }
        cout << xs << endl;
        // for (auto vl : ao)
        //     cout
        //         << vl << " ";
        // cout << endl;
        // for (auto vl : bo)
        //     cout
        //         << vl << " ";
        // cout << endl;
        // cout << "then" << endl;

        // for (auto vl : ae)
        //     cout << vl << " ";
        // cout << endl;
        // for (auto vl : be)
        //     cout
        //         << vl << " ";
        // cout << endl;
        // cout << endl;

    } else {
        minus;
    }
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