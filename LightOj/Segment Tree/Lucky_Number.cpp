#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 200
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
vector<bool> lucky(N, 0);
void pre() {
    for (int i = 1; i < N; i++)
        if (i & 1)
            lucky[i] = 1;
    for (int i = 2; i < 200; i++) {
        int cnt = 0, take = -1;
        for (int j = 1; j < N; j++) {
            if (!lucky[j])
                continue;
            cnt++;
            if (cnt == i && take == -1)
                take = j;
            if (take != -1 && (cnt % take) == 0) {
                lucky[j] = 0;
                cout << j << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void marwan(int cs) {
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}