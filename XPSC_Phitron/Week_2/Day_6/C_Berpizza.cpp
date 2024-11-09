#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, count = 1;
    cin >> n;
    set<pair<int, int>> s;
    multiset<pair<int, int>> m;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            s.insert({count, x});
            m.insert({x, -count});
            count++;
        }
        else if (op == 2)
        {
            int pos = s.begin()->first, x = s.begin()->second;
            cout << pos << " ";
            s.erase(s.begin());
            m.erase({x, -pos});
        }
        else
        {
            int pos = -m.rbegin()->second, x = m.rbegin()->first;
            cout << pos << " ";
            m.erase(--m.end());
            s.erase({pos, x});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}