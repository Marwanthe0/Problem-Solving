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
    for (auto &vl : v)
        cin >> vl;
    int i = 0, j = n - 1;
    int flag = 1;
    while (i < j) {
        if (v[i] == v[j]) {
            i++, j--;
        } else {
            flag = 0;
            break;
        }
    }
    if (flag) {
        yes;
        return;
    }
    i = 0, j = n - 1;
    vector<int> low, high;
    while (i < j) {
        if (v[i] == v[j]) {
            i++, j--;
            continue;
        } else if (abs(v[i] - v[j]) == 2) {
            low.push_back(min(v[i], v[j]));
            high.push_back(max(v[i], v[j]));
            i++, j--;
        } else {
            no;
            return;
        }
    }
    sort(all(low));
    sort(all(high));
    if (low.back() >= high.front()) {
        no;
        return;
    }
    yes;
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