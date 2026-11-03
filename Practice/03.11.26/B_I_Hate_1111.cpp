#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
vector<int> cands;
map<int, int> m, t;
bool f(int sum) {
    if (sum <= 0)
        return sum == 0;
    if (m.count(sum))
        return m[sum];
    bool ans = false;
    for (auto cand : cands) {
        if (cand <= sum)
            ans |= f(sum - cand);
    }
    return m[sum] = ans;
}
void marwan() {
    int n;
    cin >> n;
    if (t.count(n)) {
        no;
    } else
        yes;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 11; i <= 1e9; i = (i * 10) + 1) {
        cands.push_back(i);
    }
    for (int i = 1; i <= 1111; i++) {
        if (!f(i))
            t[i]++;
    }
    int tc;
    cin >> tc;
    while (tc--)
        marwan();
    return 0;
}