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
    for (int i = 0; i <= 100; i++) {
        cout << i << " " << i + 1 << ":::";
        int count = 0;
        for (int j = max(__lg(i), __lg(i + 1)); j >= 0; j--) {
            if (((i >> j) & 1) != ((i + 1) >> j) & 1)
                count++;
        }
        cout << count << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}