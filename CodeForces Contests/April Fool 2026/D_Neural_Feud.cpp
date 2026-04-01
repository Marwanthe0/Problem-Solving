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
    int n;
    cin >> n;
    if (n == 1) {
        cout << "walk";
    } else if (n == 2 || n == 4 || n == 3) {
        cout << "no";
    } else if (n == 5 || n == 6) {
        cout << "yes";
    } else if (n == 8)
        cout << 4;
    else if (n == 7)
        cout << "backwards";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}