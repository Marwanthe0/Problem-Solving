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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    queue<int> b, c;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b')
            b.push(i);
        else if (s[i] == 'c')
            c.push(i);
    }
    int bc = 0, cb = 0;
    while (m--) {
        char x, y;
        cin >> x >> y;
        if (x == 'a')
            continue;
        if (y == 'a') {
            int ci = -1, bi = -1;
            if (!c.empty())
                ci = c.front();
            if (!b.empty())
                bi = b.front();
            if (bi == -1 && ci == -1) {
                continue;
            } else if (bi == -1) {
                if (x == 'c') {
                    s[ci] = 'a';
                    c.pop();
                } else if (cb) {
                    s[ci] = 'a';
                    c.pop();
                    cb--;
                }
            } else if (ci == -1) {
                if (x == 'b') {
                    s[bi] = 'a';
                    b.pop();
                } else if (bc) {
                    s[bi] = 'a';
                    b.pop();
                    bc--;
                }
            } else {
                if (x == 'b') {
                    if (ci < bi && cb) {
                        cb--;
                        s[ci] = 'a';
                        c.pop();
                    } else {
                        s[bi] = 'a';
                        b.pop();
                    }
                } else {
                    if (bi < ci && bc) {
                        bc--;
                        s[bi] = 'a';
                        b.pop();
                    } else {
                        s[ci] = 'a';
                        c.pop();
                    }
                }
            }
        }
        if (x == 'b' && y == 'c')
            bc++;
        if (x == 'c' && y == 'b')
            cb++;
    }
    while (cb && c.size()) {
        s[c.front()] = 'b';
        cb--;
        c.pop();
    }
    cout << s << endl;
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