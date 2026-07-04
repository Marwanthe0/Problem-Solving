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
vector<int> prime(N + 1, 0);
void sieve() {
    for (int i = 2; i * i <= N; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= N; j += i)
                prime[j] = 1;
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    vector<int> divs;
    int x = n, ans = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            ans++;
            divs.push_back(i);
        }
    }
    if (n > 1) {
        divs.push_back(n);
        ans++;
    }
    make_unique(divs);
    // for (auto vl : divs)
    //     cerr << vl << " ";
    // cerr << endl;
    // cout << ans << endl;
    cout << divs.size() + (ans - 1) << endl;
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