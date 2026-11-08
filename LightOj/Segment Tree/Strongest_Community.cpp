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

struct Query {
    int l, r, idx;
    int ord;
    static int gilbertOrder(int x, int y, int pow = 21, int rotate = 0) {
        if (pow == 0)
            return 0;
        int h = 1 << (pow - 1);
        int seg = (x < h) ? ((y < h) ? 0 : 3) : ((y < h) ? 1 : 2);
        seg = (seg + rotate) & 3;
        const int rotateDelta[4] = {3, 0, 0, 1};
        int nx = x & (h - 1);
        int ny = y & (h - 1);
        int nrot = (rotate + rotateDelta[seg]) & 3;
        int subSquareSize = 1LL << (2 * pow - 2);
        int ord = seg * subSquareSize;
        int add = gilbertOrder(nx, ny, pow - 1, nrot);
        return ord + ((seg == 1 || seg == 2) ? add : (subSquareSize - add - 1));
    }
};
struct MoBase {
  protected:
    int n;
    vector<int> a;
    vector<Query> qs;
    int curL = 0, curR = -1;
    virtual void add(int pos) = 0;
    virtual void remove(int pos) = 0;
    virtual int getAnswer() = 0;

  public:
    MoBase(const vector<int> &arr) : n((int)arr.size()), a(arr) {}
    void addQuery(int l, int r, int idx) {
        qs.push_back({l, r, idx, Query::gilbertOrder(l, r)});
    }
    vector<int> process(int qcount) {
        sort(qs.begin(), qs.end(), [](const Query &A, const Query &B) { return A.ord < B.ord; });
        vector<int> ans(qcount);
        for (const auto &Q : qs) {
            while (curL > Q.l)
                add(--curL);
            while (curR < Q.r)
                add(++curR);
            while (curL < Q.l)
                remove(curL++);
            while (curR > Q.r)
                remove(curR--);
            ans[Q.idx] = getAnswer();
        }
        return ans;
    }
};
// example
int cnt[100000], cnt2[100000]; // use for distinct number
struct MOS : MoBase {
    int ans = 0;
    MOS(const vector<int> &arr, int alphabet_size) : MoBase(arr) {
        // if you need more, resize vector
        memset(cnt, 0, sizeof cnt);
        memset(cnt2, 0, sizeof cnt2);
    }
    void add(int pos) override {
        int val = a[pos];
        cnt2[cnt[val]]--;
        cnt[val]++;
        cnt2[cnt[val]]++;
        if (cnt[val] > ans)
            ans = cnt[val];
    }
    void remove(int pos) override {
        int val = a[pos];
        cnt2[cnt[val]]--;
        if (cnt2[cnt[val]] == 0 && ans == cnt[val])
            ans--;
        cnt[val]--;
        cnt2[cnt[val]]++;
    }
    int getAnswer() override {
        return ans;
    }
};
void marwan(int cs) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    MOS mos(v, n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        mos.addQuery(l, r, i);
    }
    vector<int> ans = mos.process(q);
    for (auto vl : ans)
        cout << vl << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}