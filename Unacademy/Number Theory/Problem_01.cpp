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
vector<int> cnt(N + 1, 0), mn(N + 1, 0), mx(N + 1, 0);
int f(int n) {
    map<int, int> m;
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                m[i]++;
                count++;
            }
        }
    }
    if (n > 1)
        count++, m[n]++;
    return (m.size() == 2 && count == 2);
}
void marwan() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        // if (cnt[i] == 2 && mn[i] != mx[i])
        //     sum++;
        bool x = f(i);
        sum += x;
        if ()
    }
    cout << sum << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    for (int i = 2; i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            cnt[j]++;
            if (!mn[j])
                mn[j] = i;
            mx[j] = i;
        }
    }
    marwan();
    return 0;
}