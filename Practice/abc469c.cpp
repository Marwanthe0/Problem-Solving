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
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(all(s));
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.back() == 'o') {
            count++;
            s.pop_back();
        }
        if (!s.empty() && s.back() == 'x') {
            s.pop_back();
            count++;
        }
        cout << count << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}