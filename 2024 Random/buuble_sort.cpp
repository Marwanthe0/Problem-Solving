#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void Bubble(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < n - i; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}
void printarr(vector<int> &v)
{
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    // Printing Before Sort
    printf("Printing Before Sort:\n");
    printarr(v);
    // Using Bubble Sort
    Bubble(v);
    printf("Printing After Sort:\n");
    printarr(v);
}
int main()
{
    marwan();
    return 0;
}
