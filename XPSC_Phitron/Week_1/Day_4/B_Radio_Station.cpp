#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    for (int i = 0; i < n; i++)
    {
        string ip, name;
        cin >> name >> ip;
        mp[ip] = name;
    }
    for (int i = 0; i < m; i++)
    {
        string com, ip;
        cin >> com >> ip;
        ip.pop_back();
        cout << com << " " << ip << "; #" << mp[ip] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}