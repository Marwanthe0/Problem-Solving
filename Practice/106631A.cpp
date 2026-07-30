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
int askmul(int k) {
    cout << "MUL " << k << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
int askdiv(int k) {
    cout << "DIV " << k << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
void marwan() {
    int x = askmul(1);
    // x = (a*b)/g(a,b);
    int y = askmul(x);
    // y = a*b*x/g(a*x,b);
    int a = y / x;
    // a = x*a
    // if divide with x*a then a = 1
    // b = lcm(1,b)
    int b = askdiv(x * 1ll * a);
    cout << "ANS " << a << " " << b << endl;
    cout.flush();
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