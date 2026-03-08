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
int f(int n) {
    int sum = 0;
    for (int i = __lg(n); i >= 0; i--) {
        if (1 & (n >> i)) {
            sum++;
        }
        if (i)
            sum *= 10ll;
    }
    return sum;
}
void marwan() {
    int n, ans = 0ll;
    cin >> n;
    int x = 1;
    while (1) {
        int y = f(x);
        if (y > n)
            break;
        else
            ans++, x++;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}