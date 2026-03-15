#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = (a / 3) + (b / 3) + (c / 3) + (min({(a % 3), (b % 3), (c % 3)}));
    if ((a % 3) + (b % 3) == 4 || (b % 3) + (c % 3) == 4 || (a % 3) + (c % 3) == 4) {
        if ((a % 3 == 0 && a) || (b % 3 == 0 && b) || (c % 3 == 0 && c))
            x++;
    }
    cout << x << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}