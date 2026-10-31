#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
void marwan() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a;
    cin >> b;
    map<char, int> mp;
    for (auto c : a) {
        mp[c]++;
    }
    for (auto c : b) {
        if (!mp.count(c)) {
            no;
            return;
        } else {
            mp[c]--;
            if (mp[c] <= 0)
                mp.erase(c);
        }
    }
    // cerr << mp.size() << " " << mp['s'] << " " << mp['i'] << " " << mp['x'] << endl;
    if (mp.size() == 3 && mp['s'] == 1 && mp['i'] == 1 && mp['x'] == 1) {
        yes;
    } else
        no;
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