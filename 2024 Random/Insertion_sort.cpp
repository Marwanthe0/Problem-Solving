#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void Insertion(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < v.size(); i++)
    {
        int selected = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > selected)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = selected;
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
    // Using Insertion Sort
    Insertion(v);
    printf("Printing After Sort:\n");
    printarr(v);
}
int main()
{
    marwan();
    return 0;
}