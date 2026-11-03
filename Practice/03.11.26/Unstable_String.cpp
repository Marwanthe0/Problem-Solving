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
string s;
int n;
int xs(int x) {
    return x * (x - 1) / 2;
}
pair<int, int> f(int i, int last) {
    if (i == n) {
        return {0, 0};
    }
    pair<int, int> ans = {0, 0};
    if (s[i] == '?') {
        pair<int, int> tans = f(i + 1, 0);
        tans.first++;
        if (last == 0) {
            tans.second += xs(tans.first);
            tans.first = 0;
        }
        ans.first += tans.first, ans.second += tans.second;
        pair<int, int> tans2 = f(i + 1, 1);
        tans2.first++;
        if (last == 1) {
            tans2.second += xs(tans2.first);
            tans2.first = 0;
        }
        ans.first += tans2.first, ans.second += tans2.second;
    } else if (s[i] - '0' != last) {
        pair<int, int> tans = f(i + 1, s[i] - '0');
        tans.first++;
        ans.first += tans.first, ans.second += tans.second;
    } else {
        pair<int, int> tans = f(i + 1, s[i] - '0');
        tans.first++;
        tans.second += xs(tans.first);
        tans.first = 0;
        ans.first += tans.first, ans.second += tans.second;
    }
    return ans;
}
void marwan() {
    cin >> s;
    n = s.size();
    pair<int, int> ans = f(0, 0);
    cout << ans.first << " " << ans.second << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}