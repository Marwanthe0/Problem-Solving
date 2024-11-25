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
    vector<int> v(n);
    string s;
    vector<int> cnt(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        s.push_back(cnt[v[i]] + 'a');
        cnt[v[i]]++;
    }
    cout << s << endl;
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