#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s;
    cin >> s;
    vector<pair<char, int>> x;
    int n = s.size();
    char a = s[0], b = s[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] >= min(a, b) && s[i] <= max(a, b))
            x.push_back({s[i], i + 1});
    }
    sort(x.begin(), x.end());
    if (a > b)
        reverse(x.begin(), x.end());
    cout << abs(a - b) << " " << x.size() + 2 << endl;
    cout << 1 << " ";
    for (auto vl : x)
        cout << vl.second << " ";
    cout << n;
    cout << endl;
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