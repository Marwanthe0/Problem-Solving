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
vector<int> v;
void marwan() {
    int x, y;
    cin >> x >> y;
    auto sq = [&](int a) { return a * 1ll * a; };
    auto dst = [&](int a, int b) { return min((sq(a - y) + sq(b - x)), (sq(a - x) + sq(b - y))); };
    int ans = INT_MAX;
    int xa = 0, xb = 0, idx = 0, cnt = 1;
    for (auto vl : v) {
        cnt++;
        if (vl > x + y)
            break;
        // cerr << x << " " << y << endl;
        // for (int i = 0; i <= vl / 2; i++) {
        //     cerr << i << " " << (vl - i) << " " << min(dst(vl - i, i), dst(i, vl - i)) << endl;
        //     // if (ans > min(dst(vl - i, i), dst(i, vl - i)))
        //     //     ans = min(dst(vl - i, i), dst(i, vl - i)), xa = i, xb = vl - i;
        // }
        // cerr << endl;
        int l = 0, r = vl / 2 + (vl % 2);
        int tdst = INT_MAX, tl = 0;
        if (r - l + 1 == 2) {
            int i = dst(l, vl - l), j = dst(r, vl - r);
            // cerr << l << " " << r << "::" << i << " " << j << endl;
            if (i < ans) {
                ans = i, xa = l, xb = vl - l, idx = cnt;
            }
            if (j < ans)
                ans = j, xa = r, xb = vl - r, idx = cnt;
        } else {
            while (l <= r) {
                int mid = l + (r - l) / 2;
                // if (mid == 0 || mid == (vl / 2) + (vl % 2)) {
                //     tdst = dst(mid, vl - (mid)), tl = l;
                //     break;
                // }
                if (r - l + 1 == 2) {
                    int i = dst(l, vl - l), j = dst(r, vl - r);
                    // cerr << l << " " << r << "::" << i << " " << j << endl;
                    if (i < j) {
                        tdst = dst(l, vl - (l)), tl = l;
                        break;
                    } else {
                        tdst = dst(r, vl - (r)), tl = r;
                        break;
                    }
                } else if (r == l) {
                    tdst = dst(l, vl - l), tl = l;
                    break;
                }
                int i = dst(mid - 1, vl - (mid - 1)), j = dst(mid, vl - mid), k = dst(mid + 1, vl - (mid + 1));
                // cerr << mid << ":::" << i << " " << j << " " << k << endl;
                if (i >= j && j <= k) {
                    tdst = dst(mid, vl - (mid)), tl = mid;
                    break;
                } else if (i >= j && j >= k) {
                    l = mid + 1;
                } else
                    r = mid - 1;
            }
            // cerr << tdst << " " << tl << " " << vl - tl << endl;
            if (tdst < ans)
                ans = tdst, xa = tl, xb = vl - tl, idx = cnt;
            // cerr << endl;
        }
    }
    idx--;
    // cout << ans << " " << xa << " " << xb << endl;
    // cout << idx << " " << xa << " " << xb << " " << ans << endl;
    int mn = xa;
    int rem = idx, sm = 0;
    cnt = 1;
    while (sm + cnt * rem < mn) {
        // cout << cnt << " " << rem << " " << sm + cnt * rem << endl;
        sm += cnt;
        cnt++;
        rem--;
    }
    int ttl = sm + cnt * rem;
    // cout << cnt << " " << rem << " " << sm + cnt * rem << endl;
    int agercnt = ttl - mn;
    vector<int> uttor;
    for (int i = 1; i < cnt - 1; i++) {
        uttor.push_back(i);
    }
    for (int i = 0; i < agercnt + (cnt - 1 > 0); i++)
        uttor.push_back(cnt - 1);
    while ((int)uttor.size() < idx)
        uttor.push_back(cnt);
    string last;
    for (int i = 0; i < (int)uttor.size(); i++) {
        // cerr << uttor[i] << " ";
        if (i == 0) {
            if (uttor[i])
                last.push_back('X');
            else
                last.push_back('Y');
        } else if (uttor[i] != uttor[i - 1]) {
            last.push_back('X');
        } else
            last.push_back('Y');
    }
    cerr << xa << " " << xb << endl;
    cerr << last << endl;
    if ((sq(x - xb) + sq(y - xa)) < (sq(x - xa) + sq(y - xb))) {
        for (auto c : last)
            if (c == 'X')
                cout << 'Y';
            else
                cout << 'X';
        cout << endl;
    } else
        cout << last << endl;
    // cerr << endl;
    // cerr << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int sum = 0ll;
    for (int i = 1; i <= 2e4; i++) {
        sum += i;
        v.push_back(sum);
        // cout << sum << " ";
    }
    // return 0;
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}