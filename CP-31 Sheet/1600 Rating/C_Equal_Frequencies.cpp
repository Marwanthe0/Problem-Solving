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
char nxt(char c) {
    if (c == 'z')
        return 'a';
    return (char)(c + 1);
}
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    vector<int> dv;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            dv.push_back(i);
            if (n / i != i)
                dv.push_back(n / i);
        }
    }
    make_unique(dv);
    set<char> st;
    for (char c = 'a'; c <= 'z'; c++)
        st.insert(c);
    queue<int> q;
    for (auto vl : dv) {
        string temp;
        int count = 0;
        for (auto &[c, y] : m) {
            if (y == vl) {
                temp.push_back(c);
                continue;
            }
            if (y > vl) {
                char t;
                if (q.empty())
                    t = next(c);
                else {
                    t = q.front();
                    q.pop();
                }
                temp.push_back(c);
                m[t]++;
                count++;
            } else if (y < vl) {
                q.push(c);
                m[c]++;
                temp.push_back(c);
            }
        }
        if (count <)
    }
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