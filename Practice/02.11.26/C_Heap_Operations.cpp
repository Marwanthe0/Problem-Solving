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
    int n;
    cin >> n;
    multiset<int> ms;
    vector<string> ans;
    auto insert = [&](int x) {
        ms.insert(x);
        string t = "insert " + to_string(x);
        ans.push_back(t);
    };
    auto rmv = [&] {
        ms.erase(ms.begin());
        ans.push_back("removeMin");
    };
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "insert") {
            int x;
            cin >> x;
            insert(x);
        } else if (op == "getMin") {
            int x;
            cin >> x;
            if (ms.empty())
                insert(x);
            else {
                while (!ms.empty() && *ms.begin() < x) {
                    rmv();
                }
                if (ms.empty() || *ms.begin() > x) {
                    insert(x);
                }
            }
            ans.push_back(op + " " + to_string(x));
        } else if (op == "removeMin") {
            if (ms.empty()) {
                insert(-1e9);
            }
            rmv();
        }
    }
    cout << ans.size() << endl;
    for (auto s : ans)
        cout << s << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}