#include <bits/stdc++.h>
using namespace std;

int main()
{
    // // your code goes here
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    //     int x = 0, y = 0;
    for (int n = 1; n <= 100; n++)
    {
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i & 1)
                    x++;
                else
                    y++;
            }
        }
        cout << x << " " << y << endl;
    // }
}
}
