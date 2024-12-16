#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
char t(char a)
{
    if (a == 'a')
        return 'b';
    return 'a';
}
void marwan()
{
    int n;
    cin >> n;
    char a = 'a';
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && i % 2 != 0)
        {
            a = t(a);
        }
        cout << a;
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}