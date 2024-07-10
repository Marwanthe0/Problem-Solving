#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    queue<int> a, b;
    stack<int> c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    while (!a.empty())
    {
        int x = a.front();
        c.push(x);
        a.pop();
    }
    while (!c.empty())
    {
        int x = c.top();
        b.push(x);
        c.pop();
    }
    while (!b.empty())
    {
        cout << b.front() << " ";
        b.pop();
    }
    cout << endl;
}
int main()
{
    marwan();
    return 0;
}