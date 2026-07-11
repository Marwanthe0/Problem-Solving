#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> g;
vector<int> leaves;
struct tup {
  public:
    int val, three, two;
    tup(int val, int three, int two) {
        this->val = val;
        this->three = three;
        this->two = two;
    }
};
vector<tup> lvs;
int dfs(int nd, int p) {
    int childs = 0;
    for (auto child : g[nd]) {
        if (child != p) {
            childs += dfs(child, nd);
        }
    }
    if (childs == 0)
        return leaves[nd] = 1;
    else
        return leaves[nd] = childs;
}
tup dfs2(int nd, int p) {
    int childs = 0;
    tup tans(0, 0, 0);
    bool thr = true, tw = true;
    for (auto child : g[nd]) {
        if (child != p) {
            tup temp = dfs2(child, nd);
            childs += temp.val;
            if (temp.three)
                thr = false;
            if (temp.two)
                tw = false;
        }
    }
    if (!childs) {
        tans.val = 1;
    } else {
        tans.val = childs;
        if (thr && childs % 3 == 0)
            tans.three = 1;
        if (tw && childs % 3 == 2)
            tans.two = 1;
    }
    lvs[nd] = tans;
    if (!tw)
        tans.two = 1;
    if (!thr)
        tans.three = 1;
    return tans;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    leaves.assign(n + 1, 0);
    lvs.assign(n + 1, tup(0, 0, 0));
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int leafes = dfs(1, -1);
    int two = 0, three = 0;
    if (leafes % 3 == 0) {
        yes;
        return;
    }
    dfs2(1, -1);
    for (int i = 1; i <= n; i++) {
        // cout << lvs[i].val << " " << lvs[i].two << " " << lvs[i].three << endl;
        two += lvs[i].two, three += lvs[i].three;
    }
    if (leafes % 3 == 1 && (two || three >= 2)) {
        yes;
        return;
    }
    if (leafes % 3 == 2 && (three || two >= 2)) {
        yes;
        return;
    }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}