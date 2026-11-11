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
void marwan(int cs) {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if (t.size() > 2)
            sort(t.begin() + 1, t.end() - 1);
        m[t]++;
    }
    int k;
    cin >> k;
    cin.ignore();

    for (int i = 0; i < k; i++) {
        string s;
        getline(cin, s);
        s = s + " ";
        string t;

        int tans = 1;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                if (t.size() > 2)
                    sort(t.begin() + 1, t.end() - 1);
                if (t.size() > 0) tans *= m[t];
                t.clear();
            } else {
                t.push_back(s[j]);
            }
        }
        cout << tans << endl;
    }
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