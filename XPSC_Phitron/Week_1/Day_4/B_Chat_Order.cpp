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
    map<string, int> m;
    stack<string> st;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        st.push(s);
        m[s]++;
    }
    while (!st.empty())
    {
        if (m[st.top()] == 1)
            cout << st.top() << endl;
        else
        {
            if (m[st.top()] != -1)
                cout << st.top() << endl;
            m[st.top()] = -1;
        }
        st.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}