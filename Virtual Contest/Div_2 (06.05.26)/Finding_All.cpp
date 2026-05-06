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
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1)
            a++;
        else if (x == 0)
            b++;
        else
            c++;
    }
    vector<int> ans;
    if ((a && c) || (a == 0 && c == 0)) {
        ans.push_back(0);
    }
    if (a < c)
        ans.push_back(-1);
    else if (a > c)
        ans.push_back(1);
    sort(all(ans));
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
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