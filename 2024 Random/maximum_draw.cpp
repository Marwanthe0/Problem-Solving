#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    multiset<int> s;
    for (int i = 0; i < 3; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    while (s.size() > 1)
    {
        if (*s.begin() == 0)
        {
            s.erase(s.begin());
        }
        else
        {
            ans += 1;
            int first = *s.begin();
            int last = *s.rbegin();
            s.erase(s.begin());
            s.erase(--s.end
            first--, --last;
            s.insert(first);
            s.insert(last);
        }
    }
    cout << ((*s.begin() % 2) ? -1 : ans) << "\n";
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