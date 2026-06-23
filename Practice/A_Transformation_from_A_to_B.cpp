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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, k;
vector<int> ans;
bool f(int i) {
    if (i == k) {
        ans.push_back(k);
        return true;
    }
    if (i > k)
        return false;
    if (f(i * 2)) {
        ans.push_back(i);
        return true;
    } else if (f(10 * i + 1)) {
        ans.push_back(i);
        return true;
    }
    return false;
}
void marwan() {
    cin >> n >> k;
    bool uttor = f(n);
    if (uttor) {
        yes;
        reverse(all(ans));
        cout << ans.size() << endl;
        for (auto vl : ans)
            cout << vl << " ";
    } else
        no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}