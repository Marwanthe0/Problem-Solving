#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> nge(vector<int> v)
{
    vector<int> nge(v.size(), 0);
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nge;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> NGE = nge(v);
    for (int i = 0; i < n; i++)
        cout << ((NGE[i] == 0) ? -1 : v[NGE[i]]) << " ";
    cout << endl;
    return 0;
}