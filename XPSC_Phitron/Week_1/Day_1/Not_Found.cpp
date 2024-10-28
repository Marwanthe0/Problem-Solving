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
    vector<int> v(26, 0);
    for (auto c : s)
        v[c - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (v[i] == 0)
        {
            cout << (char)(i + 'a') << endl;
            return;
        }
    }
    cout << "None\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}