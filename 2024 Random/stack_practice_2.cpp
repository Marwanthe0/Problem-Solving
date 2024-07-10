#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    stack<int> st;
    queue<int> q;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    if (n != m)
    {
        no;
        return;
    }
    while (!st.empty())
    {
        if (st.top() != q.front())
        {
            no;
            return;
        }
        st.pop(), q.pop();
    }
    yes;
}
int main()
{
    marwan();
    return 0;
}