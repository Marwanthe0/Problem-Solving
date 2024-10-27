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
    char f = '0';
    while (s.size() < 4)
    {
        s = f + s;
    }
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}