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
int n, m;
vector<string> g;
vector<vector<int>> v;
int f(vector<int> &v) {
    int n = v.size();
    vector<int> pf(n, 0), sf(n, 0);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++) {
        while (st.top() != -1 && v[st.top()] >= v[i])
            st.pop();
        pf[i] = st.top();
        st.push(i);
    }
    while (st.size())
        st.pop();
    st.push(n);
    for (int i = n - 1; i >= 0; i--) {
        while (st.top() != n && v[st.top()] >= v[i])
            st.pop();
        sf[i] = st.top();
        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int left = i - pf[i], right = sf[i] - i;
        ans = max(ans, (left + right - 1) * v[i]);
    }
    return ans;
}
void marwan(int cs) {
    cin >> n >> m;
    g.assign(n, string());
    v.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            v[i][j] = 1 - (g[i][j] - '0');
        }
    }
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i][j])
                cnt++;
            else
                cnt = 0;
            v[i][j] = cnt;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, f(v[i]));
    }
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