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
    int n, q;
    cin >> n >> q;
    int unread = 0, l = 0;
    vector<bool> read(n);
    vector<int> messages;
    vector<queue<int>> qs(n + 1, queue<int>());
    for (int i = 0; i < q; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            qs[x].push(messages.size());
            messages.push_back(x);
            // cerr << x << " " << m[x] << endl;
            unread++;
        } else if (op == 2) {
            while (qs[x].size()) {
                int nd = qs[x].front();
                if (!read[nd])
                    read[nd] = 1, unread--;
                qs[x].pop();
            }
        } else {
            while (l < x) {
                int vl = messages[x];
                if (qs[vl].size() && qs[vl].front() < x) {
                    if (read[qs[vl].front()] == 0)
                        unread--, read[qs[vl].front()] = 1;
                    qs[vl].pop();
                }
            }
        }
        cout << unread << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}