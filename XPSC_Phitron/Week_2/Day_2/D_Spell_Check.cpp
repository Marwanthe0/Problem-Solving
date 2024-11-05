#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
map<char, int> m = {{'T', 1}, {'i', 1}, {'m', 1}, {'u', 1}, {'r', 1}};
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.size() != 5)
    {
        no;
        return;
    }
    set<char> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(s[i]);
        if (m[s[i]] == 0)
        {
            no;
            return;
        }
    }
    if (st.size() != 5)
    {
        no;
        return;
    }
    yes;
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