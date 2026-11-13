#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 100000007
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
vector<int> fact(N + 5, 0ll), ifact(N + 5, 0ll);
int mod(int x, int m = M) { return (x % m + m) % m; }
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = mod(ans * 1ll * a);
        a = mod(a * 1ll * a);
        b >>= 1;
    }
    return mod(ans);
}
void pre() {
    fact[0] = 1ll;
    for (int i = 1; i <= N; i++)
        fact[i] = mod(fact[i - 1] * 1ll * i);
    ifact[N] = binexp(fact[N], M - 2);
    for (int i = N; i > 0; i--) {
        ifact[i - 1] = mod(ifact[i] * 1ll * i);
    }
}
int nCr(int n, int r) {
    if (n < r || r < 0)
        return 0ll;
    if (r == 0 || n == r)
        return 1ll;
    return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan(int cs) {
    int box, k, stars;
    cin >> box >> k >> stars;
    stars -= box; // 1 stars given to all boxes
    int bars = box - 1; //Always fixed

    // Initially calculating all ways without considering upper bound
    int total = nCr(stars + bars, bars); 
    int ml = -1;
    int cnt = 1;
    while (cnt * k <= stars) {
        //If we take cnt boxes then number of ways of choosing such boxes
        int box_ways = nCr(box, cnt);
        
        //If we take cnt boxes and give them exactly k stars then remaining variable stars
        //k...end all will come into consideration cause we will distriute them among the remaining boxes
        int rem_stars = stars - (cnt * k);

        //ways when we gave exactly k stars to cnt boxes and distribute remaining stars
        int ways = mod(box_ways * 1ll * nCr(rem_stars + bars, bars));

        //inclusion-exclusion
        total = mod(total + mod(ways * ml));
        ml *= -1;
        
        cnt++;
    }
    cout << total << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}