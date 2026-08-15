#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int k;
    cin >> k;
    long long dig = 1, cnt = 9, sum = 0;
    while (k > sum + (dig * 1ll * cnt)) {
        sum += (dig * 1ll * cnt);
        dig++;
        cnt = (cnt * 10ll);
    }
    cerr << dig << " " << cnt << " " << k - sum << endl;
    int koto_tomo = (k - sum) / dig, age_ase = pow(10, dig - 1) - 1;
    cerr << koto_tomo << " " << age_ase << " " << age_ase + koto_tomo << endl;
    int x = age_ase + koto_tomo;
    cout << x << endl;
    // if (((x / 10) % 10) & 1) {
    // }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}