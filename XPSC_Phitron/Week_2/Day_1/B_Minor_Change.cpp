#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string a, b;
    cin >> a >> b;
    ll count = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            count++;
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}