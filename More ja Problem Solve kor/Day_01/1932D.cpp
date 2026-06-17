#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
map<char, int> m = {{'C', 0}, {'D', 1}, {'H', 2}, {'S', 3}};
string ts = "CDHS";
void marwan() {
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    vector<vector<int>> v(4);
    for (int i = 0; i < 2 * n; i++) {
        string x;
        cin >> x;
        v[m[x[1]]].push_back(x[0] - '0');
    }
    int tr = m[trump];
    sort(all(v[tr]));
    vector<pair<string, string>> ans;
    for (int i = 0; i < 4; i++) {
        if (i == tr)
            continue;
        sort(all(v[i]));
        for (int j = 0; j < v[i].size(); j++) {
            if (j == v[i].size() - 1) {
                if (v[tr].size()) {
                    string a, b;
                    a += v[i][j] + '0', b += v[tr].back() + '0';
                    v[tr].pop_back();
                    a += ts[i];
                    b += trump;
                    ans.push_back({a, b});
                } else {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
            } else {
                string a, b;
                a += v[i][j] + '0', b += v[i][j + 1] + '0';
                a += ts[i], b += ts[i];
                ans.push_back({a, b});
                j++;
            }
        }
    }
    if (v[tr].size() & 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int j = 0; j < v[tr].size(); j += 2) {
        string a, b;
        a += v[tr][j] + '0', b += v[tr][j + 1] + '0';
        a += trump, b += trump;
        ans.push_back({a, b});
    }
    for (auto [x, y] : ans)
        cout << x << " " << y << endl;
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