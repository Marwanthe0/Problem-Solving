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
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (auto c : s) {
        m[c]++;
    }
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i) {
                div.push_back(n / i);
            }
        }
    }
    vector<pair<char, int>> chars;
    for (auto &[x, y] : m) {
        chars.push_back({x, y});
    }
    sort(all(chars), [&](pair<char, int> a, pair<char, int> b) {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second; });
    make_unique(div);
    auto nxt = [&](map<char, int> &mt) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (!mt.count(ch))
                return ch;
        }
        return '!';
    };
    string stans = s;
    int ans = INT_MAX;
    for (auto d : div) {
        // cerr << d << " ";
        unordered_map<char, int> mt;
        string t = s;
        int char_lagbe = n / d, op = 0;
        unordered_set<char> tholi, barbo, kombo;
        for (int i = 0; i < min(char_lagbe, (int)chars.size()); i++) {
            tholi.insert(chars[i].first);
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if ((int)tholi.size() >= char_lagbe)
                break;
            if (!tholi.count(ch)) {
                tholi.insert(ch);
            }
        }
        // cerr << endl;
        for (auto c : tholi) {
            mt[c] = d;
            // cerr << c << " " << d << endl;
        }
        map<char, int> adjust;
        int tt = 0;
        for (auto [x, y] : m) {
            if (mt[x] - y) {
                adjust[x] = mt[x] - y;
            }
        }
        for (auto [x, y] : mt) {
            if (!m.count(x)) {
                adjust[x] += y;
            }
        }
        for (auto [x, y] : adjust) {
            tt += y;
            if (y > 0) {
                op += y;
                barbo.insert(x);
            }
            // cerr << x << " " << y << endl;
        }
        if (tt) {
            continue;
        }
        // cerr << endl;
        // for (auto c : barbo)
        //     cerr << c << " ";
        // cerr << endl;
        for (int i = 0; i < t.size(); i++) {
            char c = t[i];
            if (!adjust.count(c))
                continue;
            if (adjust[c] < 0) {
                adjust[c]++;
                if (adjust[c] == 0) {
                    adjust.erase(adjust.find(c));
                }
                char nc = *barbo.begin();
                adjust[nc]--;
                if (adjust[nc] == 0) {
                    adjust.erase(adjust.find(nc));
                    barbo.erase(barbo.find(nc));
                }
                t[i] = nc;
            }
        }
        if (op < ans)
            ans = op, stans = t;
    }
    // cerr << endl;
    cout << ans << endl;
    cout << stans << endl;
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