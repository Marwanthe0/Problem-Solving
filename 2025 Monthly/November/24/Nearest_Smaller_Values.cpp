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
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    stack<pair<int, int>> st;
    st.push({INT_MAX, 0});
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= v[i])
            st.pop();
        if (st.empty())
            cout << 0 << " ";
        else
            cout << st.top().second << " ";
        st.push({v[i], i + 1});
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}