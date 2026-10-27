#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void f() {
  cout << 3 << " * " << 4 << " = " << 12 << endl;
  cout << 12 << " * " << 2 << " = " << 24 << endl;
  cout << 24 << " * " << 1 << " = " << 24 << endl;
}
void f2(int n) {
  cout << n << " + " << n + 3 << " = " << 2 * n + 3 << endl;
  cout << n + 1 << " + " << n + 2 << " = " << 2 * n + 3 << endl;
  cout << 2 * n + 3 << " - " << 2 * n + 3 << " = " << 0 << endl;
  cout << 0 << " + " << 24 << " = " << 24 << endl;
}

void add(int a, int b) { cout << a << " + " << b << " = " << a + b << endl; }
void sub(int a, int b) { cout << a << " - " << b << " = " << a - b << endl; }
void mul(int a, int b) { cout << a << " * " << b << " = " << a * b << endl; }
void marwan() {
  int n;
  cin >> n;
  if (n < 4) {
    no;
    return;
  }
  if (n == 5) {
    yes;
    cout << 5 << " * " << 3 << " = " << 15 << endl;
    cout << 2 << " * " << 4 << " = " << 8 << endl;
    cout << 15 << " + " << 8 << " = " << 23 << endl;
    cout << 23 << " + " << 1 << " = " << 24 << endl;
    return;
  }
  if (n == 6) {
    yes;
    cout << 3 << " * " << 4 << " = " << 12 << endl;
    cout << 12 << " * " << 2 << " = " << 24 << endl;
    cout << 5 << " - " << 6 << " = " << -1 << endl;
    cout << -1 << " + " << 1 << " = " << 0 << endl;
    cout << 0 << " + " << 24 << " = " << 24 << endl;
    return;
  }
  if ((n - 4) % 4 == 0) {
    yes;
    f();
    for (int i = 5; i <= n; i += 4) {
      f2(i);
    }
    return;
  } else if ((n - 4) % 4 == 2) {
    yes;
    cout << 3 << " * " << 4 << " = " << 12 << endl;
    cout << 12 << " * " << 2 << " = " << 24 << endl;
    for (int i = 5; i + 2 <= n; i += 4) {
      f2(i);
    }
    cout << n - 1 << " - " << n << " = " << -1 << endl;
    cout << -1 << " + " << 1 << " = " << 0 << endl;
    cout << 0 << " + " << 24 << " = " << 24 << endl;
    return;
  } else if ((n - 4) % 4 == 3) {
    yes;
    mul(6, 4);
    sub(7, 3);
    sub(5, 2);
    add(3, 1);
    sub(4, 4);
    add(0, 24);
    for (int i = 8; i <= n; i += 4) {
      f2(i);
    }
    return;
  } else if ((n - 4) % 4 == 1) {
    yes;
    mul(8, 3);
    sub(7, 9);
    sub(4, 2);
    add(-2, 2);
    add(0, 24);
    sub(5, 6);
    add(-1, 1);
    add(0, 24);
    for (int i = 10; i <= n; i += 4) {
      f2(i);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}