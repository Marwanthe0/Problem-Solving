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
int f(int a, int b) {
    int count = 0;
    while (a != 0 && b != 0) {
        if (a >= b) {
            int res = (a / b);
            count += res;
            a -= res * b;
        } else {
            int res = (b / a);
            count += res;
            b -= res * a;
        }
    }
    return count;
}
string ans(int a, int b) {
    if (min(a, b) == 0 && max(a, b) == 1)
        return "";
    if (a >= b) {
        return ans(a - b, b) + "T";
    } else if (a < b)
        return ans(a, b - a) + "B";
}
void marwan() {
    int n, r;
    cin >> n >> r;
    int mx = INT_MAX;
    string gans;
    for (int i = 1; i <= r; i++) {
        if (__gcd(i, r) == 1) {
            if (n == f(i, r)) {
                string curans = ans(i, r);
                int count = 0;
                for (int j = 1; j < n; j++) {
                    if (curans[j] == curans[j - 1])
                        count++;
                }
                if (count < mx) {
                    mx = count, gans = curans;
                }
                // cerr << count << " " << curans << endl;
            }
            if (n == f(r, i)) {
                int count2 = 0;
                string curans2 = ans(r, i);
                for (int j = 1; j < n; j++) {
                    if (curans2[j] == curans2[j - 1])
                        count2++;
                }
                if (count2 < mx) {
                    mx = count2, gans = curans2;
                }
            }
        }
    }
    if (mx == INT_MAX)
        cout << "IMPOSSIBLE" << endl;
    else {
        cout << mx << endl;
        cout << gans;
        cout << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}
