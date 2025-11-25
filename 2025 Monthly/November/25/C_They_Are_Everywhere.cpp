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
    string s;
    cin >> s;
    set<char> st;
    map<char, int> m;
    for (auto c : s)
        st.insert(c);
    int k = st.size();
    int l = 0, r = 0, ans = n;
    while (r < n)
    {
        m[s[r]]++;
        while (m.size() >= k)
        {
            ans = min(ans, r - l + 1);
            m[s[l]]--;
            if (m[s[l]] <= 0)
                m.erase(s[l]);
            l++;
        }
        r++;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}