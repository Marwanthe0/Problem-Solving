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
vector<int> v(1e6);
int f(int n) {
    int x = 5ll, sum = 0;
    while (x <= n) {
        sum += n / x;
        x *= 5ll;
    }
    return sum;
}
void marwan() {
    int n;
    cin >> n;
    if (v[n] == -1)
        cout << 0 << endl;
    else {
        cout << 5 << endl;
        for (int i = 0; i < 5; i++)
            cout << v[n] + i << " ";
        cout << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 1e6; i++)
        v[i] = -1;
    for (int i = 0; i < 1e6; i += 5) {
        v[f(i)] = i;
    }
    marwan();
    return 0;
}