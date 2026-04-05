#include <bits/stdc++.h>

using namespace std;

long double randomFloat() {
    return (long double)(rand()) / (long double)(RAND_MAX);
}
bool dist(long double a, long double b, long double r) {
    return sqrt((abs(r - a)) * (abs(r - a)) + (abs(r - b) * abs(r - b))) <= r;
}
signed main() {
    srand(time(0));
    long double n;
    cin >> n;
    long double mn = INT_MAX, mx = INT_MIN;
    int count = 0;
    for (int i = 0; i < 1000000; i++) {
        long double x = randomFloat(), y = randomFloat();
        x *= n, y *= n;
        if (dist(x, y, n / 2.0)) {
            count++;
        }
    }
    cout << 4 * ((long double)count / 1000000);

    return 0;
}