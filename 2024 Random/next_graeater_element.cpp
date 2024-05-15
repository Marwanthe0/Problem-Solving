#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> nge(vector<int> v)
{
    stack<int> st;
    vector<int> nge(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> NGE = nge(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " " << ((NGE[i] == -1) ? -1 : v[NGE[i]]) << endl;
}
int main()
{
    marwan();
    return 0;
}