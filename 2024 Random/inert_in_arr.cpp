#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
/*Insertion in an array*/
void marwan()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int idx, val;
    cin >> idx >> val;
    int x = n;
    while (idx < n)
    {
        arr[n--] = arr[n - 1];
    }
    arr[idx] = val;
    for (int i = 0; i <= x; i++)
        cout << arr[i] << " ";
}
/*Deletion in an array*/
// void marwan()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     int idx;
//     cin >> idx;
//     while (idx < n)
//         arr[idx++] = arr[idx + 1];
//     for (int i = 0; i < n - 1; i++)
//         cout << arr[i] << " ";
// }
int main()
{
    marwan();
    return 0;
}