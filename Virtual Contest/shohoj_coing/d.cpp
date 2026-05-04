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
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int sum = accumulate(all(v), 0ll);
    int sum2 = sum - v[0];
    sort(v.begin() + 1, v.end(), greater<int>());
    vector<int> ans;

    int alice = v[0];
    for (int i = 1; i < n; i++) {
        if (sum / 2 < alice)
            break;
        if (v[i] * 2 <= alice) {
            alice += v[i];
            sum -= v[i];
            ans.push_back(v[i]);
        }
    }
    if(alice <)
    for(auto )
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}