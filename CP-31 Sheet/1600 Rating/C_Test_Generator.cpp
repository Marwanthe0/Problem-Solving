#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void print(int a, int mx) {
    for (int i = mx; i >= 0; i--)
        cerr << (1 & (a >> i));
    cerr << endl;
}
void marwan() {
    int a, b;
    cin >> a >> b;
    int mx = max(__lg(a), __lg(b));
    print(a, mx);
    print(b, mx);
    cerr << endl;
    for (int i = 0; i < mx; i++) {
        if (1 & (b >> i))
            break;
        else if (1 & (a >> i)) {
            minus;
            return;
        }
    }
    int x = a, y = b, count = 0ll;
    while (x) {
        y = b;
        int thakbe = __builtin_popcount(x), barbe = 0;
        int barabo, cmx = INT_MAX;
        while (y) {
            int curthakbe = __biltin_popcount(x & (~y));
            int curbarbe = barbe;
            if (curthakbe + curbarbe < cmx)
                cmx = (curthakbe + curbarbe), barabo = barbe;
            barbe++;
            y <<= 1ll;
            if (__lg(y) > __lg(x))
                y &= ~(1 << __lg(y));
        }
        // x &= ~(y);
        count += lagbe;
    }
    cout << count << endl;
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