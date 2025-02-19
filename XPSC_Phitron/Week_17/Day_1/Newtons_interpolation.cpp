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
void newtoninterpolation(double x[], double y[][10], int n, double value)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << x[i];
        for (int j = 0; j < n - i; j++)
        {
            cout << setw(5) << y[i][j];
        }
        cout << endl;
    }

    double sum = y[0][0];
    double u = (value - x[0]) / (x[1] - x[0]);
    double term = 1;

    for (int i = 1; i < n; i++)
    {
        term *= (u - (i - 1)) / i;
        sum += term * y[0][i];
    }

    cout << "\nvalue at x = " << value << " is " << sum << endl;
}
void marwan()
{
    int n;
    cin >> n;
    double x[n], y[n][10] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i][0];
    }

    double value;
    cin >> value;

    newtoninterpolation(x, y, n, value);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}