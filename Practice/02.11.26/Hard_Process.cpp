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
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int l = 0, r = 0, ans = 0, anspos = 0, count = 0;
    while (r < n) {
        if (!v[r])
            count++;
        while (count > k) {
            if (!v[l])
                count--;
            l++;
        }
        if (r - l + 1 > ans)
            ans = r - l + 1, anspos = r;
        r++;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (i >= anspos - ans + 1 && i <= anspos)
            cout << 1 << " ";
        else
            cout << v[i] << " ";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}