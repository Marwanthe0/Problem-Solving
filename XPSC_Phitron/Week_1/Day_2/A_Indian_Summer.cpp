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
    set<pair<string, string>> s;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        s.insert({a, b});
    }
    cout << s.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}