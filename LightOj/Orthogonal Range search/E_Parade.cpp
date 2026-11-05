// height, start, end

// x1 y1 = start, 0 x2 y2 = end, heigh
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
struct event {
    int x, y1, y2, val;

    bool operator<(const event &other) const {
        return x < other.x;
    }
};
void marwan() {
    int n;
    cin >> n;
    vector<event> events;
    vector<int> ys;
    for (int i = 0; i < n; i++) {
        int height, start, end;
        cin >> height >> start >> end;
        int x1 = start, y1 = 0, x2 = end, y2 = height;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
        ys.push_back(y1);
        ys.push_back(y2);
    }
    make_unique(ys);
    int m = ys.size();
    sort(all(events));
    int mx = 0;
    for (auto [x, y1, y2, val] : events) {
        if (val > 0)
            mx = max(mx, y2);
        else
            mx = min(mx, y2);
        cerr << x << " " << y1 << " " << mx << " " << val << endl;
    }
    cerr << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}