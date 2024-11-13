#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
map<char, int> m = {{'S', 1}, {'M', 2}, {'L', 3}};
void marwan()
{
    string a, b;
    cin >> a >> b;
    if (m[a.back()] > m[b.back()])
        cout << '>' << endl;
    else if (m[a.back()] < m[b.back()])
        cout << '<' << endl;
    else
    {
        if (a.size() == b.size())
            cout << '=' << endl;
        else
        {
            if (a.back() == 'S')
                cout << ((a.size() > b.size()) ? "<" : ">") << endl;
            else
                cout << ((a.size() < b.size()) ? "<" : ">") << endl;
        }
    }
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