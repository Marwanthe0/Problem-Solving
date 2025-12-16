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

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    int ans = 0;
    for (auto c : tokens)
    {
        if (c.back() >= '0' && c.back()<= '9')
        {
            st.push(stoi(c));
            cerr << "Pushed" << " " << st.top() << endl;
        }
        else
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            switch (c[0])
            {
            case '+':
                ans = x + y;
                break;
            case '-':
                ans = y - x;
                break;
            case '/':
                ans = (y / x);
                break;
            case '*':
                ans = y * x;
                break;
            }
            st.push(ans);
        }
    }
    return ans;
}
void marwan()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &vl : v)
        cin >> vl;
    cout << evalRPN(v) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}