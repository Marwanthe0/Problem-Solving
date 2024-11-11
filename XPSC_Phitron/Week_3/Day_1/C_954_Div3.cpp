#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
void marwan()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string cp = s;
    set<int> st;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    string last;
    cin >> last;
    sort(last.begin(), last.end());
    last.erase(last.begin() + st.size(), last.end());
    auto it = st.begin();
    int i = 0;
    for (int i = 0; i < st.size(); i++)
    {
        s[*it - 1] = last[i];
        it++;
    }
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}