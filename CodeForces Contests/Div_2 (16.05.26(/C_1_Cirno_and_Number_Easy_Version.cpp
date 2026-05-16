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
    string a;
    int n;
    cin >> a >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    int mn = d[0];
    int mx = d[n - 1];
    int nz = -1;
    for (int i = 0; i < n; i++) {
        if (d[i] > 0) {
            nz = d[i];
            break;
        }
    }
    vector<string> v;
    int sz = a.size();
    if (sz > 1) {
        string small(sz - 1, mx + '0');
        v.push_back(small);
    }
    if (nz != -1) {
        string big = to_string(nz) + string(sz, mn + '0');
        v.push_back(big);
    } else {
        v.push_back("0");
    }
    string pf = "";
    bool flag1 = true;

    for (int i = 0; i < sz; i++) {
        int cur = a[i] - '0';
        int last = -1;
        for (int x : d) {
            if (x < cur)
                last = x;
        }
        if (last != -1) {
            string tmp = pf + to_string(last) + string(sz - 1 - i, mx + '0');
            v.push_back(tmp);
        }
        int last1 = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (d[i] > cur)
                last1 = d[i];
        }
        if (last1 != -1) {
            string tmp = pf + to_string(last1) + string(sz - 1 - i, mn + '0');
            v.push_back(tmp);
        }
        bool flag2 = false;
        for (int x : d) {
            if (x == cur)
                flag2 = true;
        }

        if (flag2) {
            pf += to_string(cur);
        } else {
            flag1 = false;
            break;
        }
    }
    if (flag1) {
        v.push_back(a);
    }
    int target = stoll(a);
    int dif = 1e17;
    for (string s : v) {
        if (s.empty())
            continue;
        int val = stoll(s);
        int dist = abs(target - val);
        if (dist < dif) {
            dif = dist;
        }
    }

    cout << dif << endl;
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