#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
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
struct event {
    int x, val, id;
    bool operator<(const event &other) const {
        return x < other.x;
    }
};
void marwan(int cs) {
    int n;
    cin >> n;
    vector<event> events;
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        events.push_back({x, 1, i + 1});
        events.push_back({y + 1, -1, i + 1});
    }
    sort(all(events));
    set<int> ans;
    multiset<int> ms;
    for (int i = 0; i < events.size(); i++) {
        auto &event = events[i];
        if (event.val > 0) {
            ms.insert(event.id);
        } else {
            ms.erase(ms.find(event.id));
        }
        if (i + 1 < events.size() && events[i + 1].x == event.x)
            continue;
        if (ms.size()) {
            ans.insert(*(--ms.end()));
        }
    }
    cout << ans.size() << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}