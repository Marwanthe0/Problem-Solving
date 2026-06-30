#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define srt(x) sort(x.begin(), x.end())
#define rvs(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()

#define pq priority_queue
#define fn function
#define dbg(v) \
    cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

template <typename K, typename V>
using umap = unordered_map<K, V>;

using i64 = int64_t;
using d64 = long double;

using p32 = pair<int, int>;
using p64 = pair<i64, i64>;
using pd = pair<d64, d64>;

using graph = vector<vector<int>>;
using wgraph = vector<vector<p64>>;

template <typename T1, typename T2>
istream &operator>>(istream &stream, pair<T1, T2> &p) {
    stream >> p.ft;
    stream >> p.sd;
    return stream;
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
istream &operator>>(istream &stream, vector<T> &v) {
    if (v.empty()) {
        unsigned long long len;
        stream >> len;
        v.assign(len, T());
    }
    for (auto i = 0; i < sz(v); i++) {
        stream >> v[i];
    }
    return stream;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++) {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const unordered_map<T1, T2> &map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (next(it) != map.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const map<T1, T2> &map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (next(it) != map.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
ostream &operator<<(ostream &out, const unordered_set<T> &set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
ostream &operator<<(ostream &out, const multiset<T> &set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
ostream &operator<<(ostream &out, const unordered_multiset<T> &set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        size_t hash1 = hash<T1>{}(p.first);
        size_t hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
    }
};

vector<i64> good_numbers;

void generate(int len, int pos, int d1, int d2, i64 cur) {
    if (pos == len) {
        if (cur >= 2 && cur <= 1000000000LL)
            good_numbers.push_back(cur);
        return;
    }

    if (pos == 0 && d1 == 0) {
    } else {
        generate(len, pos + 1, d1, d2, cur * 10 + d1);
    }

    if (d1 != d2)
        if (!(pos == 0 && d2 == 0))
            generate(len, pos + 1, d1, d2, cur * 10 + d2);
}

inline bool good(i64 x) {
    if (x == 0)
        return true;

    int mask = 0;

    while (x > 0) {
        mask |= (1 << (x % 10));

        if (__builtin_popcount(mask) > 2)
            return false;

        x /= 10;
    }

    return true;
}

void solve() {
    int X;
    cin >> X;

    for (auto &c : good_numbers) {
        if (good(c * X)) {
            cout << c << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    good_numbers.reserve(100000);

    for (int d = 0; d <= 9; d++) {
        for (int len = 1; len <= 10; len++) {
            generate(len, 0, d, d, 0);
        }
    }

    for (int d1 = 0; d1 <= 9; d1++) {
        for (int d2 = d1 + 1; d2 <= 9; d2++) {
            for (int len = 1; len <= 10; len++) {
                generate(len, 0, d1, d2, 0);
            }
        }
    }

    int idx = 0;
    auto f = [&](int x) {
        string xs = to_string(x);
        if (xs[0] != '1')
            return false;
        if (xs.back() != '1')
            return false;
        for (int i = 1; i + 1 < xs.size(); i++)
            if (xs[i] != '0')
                return false;
        return true;
    };
    // cout << f(101) << endl;
    map<int, int> m;
    for (auto it : good_numbers) {
        idx++;
        if (f(it)) {
            if (m.count(it))
                m[it] = min(m[it], idx);
            else
                m[it] = idx;
        }
    }
    for (auto [x, y] : m)
        cout << x << " " << y << endl;
    cout << endl;
    // int tc;
    // cin >> tc;

    // while (tc--) {
    //     solve();
    // }

    return 0;
}
