#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
class Student
{
public:
    string name;
    int roll;
    int marks;
};
bool cmp(Student a, Student b)
{
    if (a.marks == b.marks)
    {
        return a.roll < b.roll;
    }
    return a.marks > b.marks;
}
void marwan()
{
    int n;
    cin >> n;
    Student students[n];
    for (int i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].roll >> students[i].marks;
    }
    sort(students, students + n, cmp);
    for (auto it : students)
    {
        cout << it.name << " " << it.roll << " " << it.marks << endl;
    }
}
int main()
{
    marwan();
    return 0;
}