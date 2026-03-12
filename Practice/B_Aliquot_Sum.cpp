#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> ans(N + 10, 0ll);
void marwan() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (ans[x] == x)
            cout << "perfect" << endl;
        else if (ans[x] > x)
            cout << "abundant" << endl;
        else
            cout << "deficient" << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    for (int i = 1; i <= N; i++) {
        for (int j = i + i; j <= N; j += i)
            ans[j] += i;
    }
    marwan();
    return 0;
}