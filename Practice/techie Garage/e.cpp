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
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void multiply(vector<int> &ans, int x) {
    int carry = 0;
    for (size_t i = 0; i < ans.size(); i++) {
        int ml = ans[i] * x + carry;
        ans[i] = ml % 10;
        carry = ml / 10;
    }
    while (carry) {
        ans.push_back(carry % 10);
        carry /= 10;
    }
}
void power(int x, int k) {
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    vector<int> ans;
    ans.push_back(1);
    for (int i = 0; i < k; i++) {
        multiply(ans, x);
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
}

void marwan() {
    int x;
    cin >> x;
    int k;
    cin >> k;
    vector<int> v(k);
    for (auto &vl : v)
        cin >> vl;
    v.push_back(0);
    make_unique(v);
    k = v.size();
    power(k, x);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}