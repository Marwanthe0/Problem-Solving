#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
map<char, int> m = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
void marwan()
{
    string s;
    cin >> s;
    stack<int> st;
    for (auto c : s)
    {
        if (m[c] < 0)
            st.push(m[c]);
        else
        {
            if (st.empty())
            {
                no;
                return;
            }
            else if (m[c] != (-1) * st.top())
            {
                no;
                return;
            }
            else
                st.pop();
        }
    }
    yes;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}