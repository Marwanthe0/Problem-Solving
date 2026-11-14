#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    int y;
    cin >> y;
    if (sum >= y) {
        cout << "Let's Dance" << endl;
    } else
        cout << "Call Ambulance" << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}