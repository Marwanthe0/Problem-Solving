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
    n++;
    vector<int> v(n), pf(n, 0), sf(n, 0);
    for (int i = 1; i < n; i++)
        cin >> v[i];
    stack<int> st;
    v[0] = INT_MIN;
    v.push_back(INT_MIN);
    st.push(0);
    for (int i = 1; i < n; i++) {
        while (v[st.top()] >= v[i]) {
            st.pop();
        }
        pf[i] = st.top();
        st.push(i);
    }
    while (st.size())
        st.pop();
    st.push(n);
    for (int i = n - 1; i >= 1; i--) {
        while (v[st.top()] >= v[i])
            st.pop();
        sf[i] = st.top();
        st.push(i);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        // cerr << i << " " << pf[i] << " " << sf[i] << endl;
        ans = max(ans, v[i] * (sf[i] - pf[i] - 1));
    }
    // cerr << endl;
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}