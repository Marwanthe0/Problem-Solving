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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    multiset<int> ms;
    for (auto &vl : a) {
        cin >> vl;
        ms.insert(vl);
    }
    for (auto &vl : b)
        cin >> vl;
    sort(all(b), greater<int>());
    int j = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while (j < m && ms.lower_bound(b[j]) == ms.end()) {
            ans.push_back(b[j++]);
        }
        ans.push_back(a[i]);
        ms.erase(ms.find(a[i]));
    }
    while (j < m)
        ans.push_back(b[j++]);
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
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