#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push('(');
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else
                count++;
        }
    }
    cout << count << endl;
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