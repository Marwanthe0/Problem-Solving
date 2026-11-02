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
    string recipi;
    cin >> recipi;
    int b, s, c, rb = 0, rs = 0, rc = 0;
    cin >> b >> s >> c;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    int money;
    cin >> money;
    for (auto c : recipi)
        if (c == 'B')
            rb++;
        else if (c == 'S')
            rs++;
        else
            rc++;
    int l = 0, r = 1e15, ans = 0;

    auto ok = [&](int piece) {
        int br = rb * piece, sr = rs * piece, cr = rc * piece;
        br = max(0ll, br - b);
        sr = max(0ll, sr - s);
        cr = max(0ll, cr - c);
        int cost = br * pb + sr * ps + cr * pc;
        return cost <= money;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid, l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}