#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int lcm(int a, int b)
{
    int greater = max(a, b);
    int smallest = min(a, b);
    for (int i = greater;; i += greater)
    {
        if (i % smallest == 0)
            return i;
    }
}
void marwan()
{
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    // if (max(a, b) % min(a, b) == 0)
    // {
    //     cout << max(a, b) << endl;
    //     return;
    // }
    // int x = a * b;
    // while (x % a == 0 && x % b == 0)
    // {
    //     x /= 2;
    // }
    // cout << x * 2 << endl;
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