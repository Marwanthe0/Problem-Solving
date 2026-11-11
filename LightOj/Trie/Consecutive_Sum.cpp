#include <bits/stdc++.h>
using namespace std;
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
static const int B = 63;
static const int MAX_NODES = 50002 * (B + 1);
class BitwiseTrie {
  private:
    int trie[MAX_NODES][2];
    int cnt[MAX_NODES];
    int nodes_cnt = 40;

  public:
    BitwiseTrie() {
        reset();
    }

    void reset() {
        for (int i = 0; i < nodes_cnt; ++i) {
            trie[i][0] = trie[i][1] = 0;
            cnt[i] = 0;
        }
        nodes_cnt = 1;
    }

    int count(int num) {
        int cur = 0;
        for (int b = B; b >= 0; --b) {
            int bit = (num >> b) & 1;
            if (!trie[cur][bit])
                return 0;
            cur = trie[cur][bit];
        }
        return cnt[cur];
    }

    void insert(int num) {
        int cur = 0;
        cnt[cur]++;
        for (int b = B; b >= 0; --b) {
            int bit = (num >> b) & 1;
            if (!trie[cur][bit]) {
                trie[cur][bit] = nodes_cnt++;
            }
            cur = trie[cur][bit];
            cnt[cur]++;
        }
    }

    void remove(int num) {
        if (count(num) == 0)
            return;

        int cur = 0;
        cnt[cur]--;
        for (int b = B; b >= 0; --b) {
            int bit = (num >> b) & 1;
            cur = trie[cur][bit];
            cnt[cur]--;
        }
    }

    int queryMaxXor(int num) {
        if (cnt[0] == 0)
            return 0;
        int cur = 0, res = 0;
        for (int b = B; b >= 0; --b) {
            int bit = (num >> b) & 1;
            int want = bit ^ 1;
            if (trie[cur][want] && cnt[trie[cur][want]] > 0) {
                res |= (1LL << b);
                cur = trie[cur][want];
            } else {
                cur = trie[cur][bit];
            }
        }
        return res;
    }

    int queryMinXor(int num) {
        if (cnt[0] == 0)
            return 0;
        int cur = 0, res = 0;
        for (int b = B; b >= 0; --b) {
            int bit = (num >> b) & 1;
            if (trie[cur][bit] && cnt[trie[cur][bit]] > 0) {
                cur = trie[cur][bit];
            } else {
                res |= (1LL << b);
                cur = trie[cur][bit ^ 1];
            }
        }
        return res;
    }
} btr;
void marwan(int cs) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v) {
        cin >> vl;
    }

    int mx = 0, mn = INT_MAX;
    int x = 0;
    btr.insert(0);
    for (auto &vl : v) {
        x ^= vl;
        mx = max(mx, btr.queryMaxXor(x));
        mn = min(mn, btr.queryMinXor(x));
        btr.insert(x);
    }
    cout << mx << " " << mn << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        btr.reset();
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}