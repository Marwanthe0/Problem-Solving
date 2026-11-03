#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Ashishgup" << endl
#define no cout << "FastestFinger" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
bool isprime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void marwan(int cs) {
    int n;
    cin >> n;
    if (n == 1) {
        no;
        return;
    } else if (n == 2) {
        yes;
        return;
    }
    if (((n & (n - 1)) == 0) || ((n % 2) == 0 && isprime(n / 2)))
        no;
    else
        yes;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        marwan(i);
    }
    return 0;
}