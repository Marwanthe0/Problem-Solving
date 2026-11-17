#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
void marwan(int cs) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
        r = max(r, abs(v[i] - v[i - 1]));
    r = max(r, abs(v.back() - v.front()));
    int ans = r;
    v.push_back(v[0]);
    n++;
    auto ok = [&](int need) {
        int tk = k;
        vector<int> t = v;
        for (int i = 1; i < n; i++) {
            if (abs(t[i] - t[i - 1]) > need) {
                int dif = abs(t[i] - t[i - 1]) - need;
                // cerr << i << " " << t[i - 1] << " " << dif << endl;
                if (t[i] < t[i - 1]) {
                    if (tk >= dif) {
                        t[i] += dif;
                        tk -= dif;
                    } else
                        return false;
                    continue;
                }

                if (tk >= dif)
                    t[i - 1] += dif, tk -= dif;
                else {
                    return false;
                }

                for (int j = i - 2; j >= 0; j--) {
                    if (abs(t[j] - t[j + 1]) > need) {
                        int dif2 = abs(t[j] - t[j + 1]) - need;
                        if (tk >= dif2)
                            t[j] += dif, tk -= dif;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2, kk = ok(mid);
        // cerr << mid << " " << kk << endl;
        if (kk) {
            ans = mid, r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}