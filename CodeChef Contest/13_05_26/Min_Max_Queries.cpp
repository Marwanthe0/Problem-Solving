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
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    while (k--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            v[a - 1] = b;
        } else {
            a--, b--;
            if (a == b)
                cout << v[a] << endl;
            else {
                if ((a + b + 1) & 1) {
                    int mid = ((a + b) / 2);
                    int age = mid - 1, pore = mid + 1;
                    vector<int> vals;
                    vals.push_back(v[mid]);
                    vals.push_back(v[age]);
                    vals.push_back(v[pore]);
                    sort(all(vals));
                    if (v[mid] == vals[0])
                        cout << v[mid] << endl;
                    else if (v[mid] == vals[2])
                        cout << vals[1] << endl;
                    else
                        cout << v[mid] << endl;
                } else {
                    int mid = (a + b) / 2;
                    int pore = mid + 1;
                    cout << max(v[mid], v[pore]) << endl;
                }
            }
        }
    }
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