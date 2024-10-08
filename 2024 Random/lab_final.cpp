#include<bits/stdc++.h>
using namespace std;
void printarr(int a[],int n){
    for(int i = 0;i < n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
void bubbleSort(int a[],int n){
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n - i;j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
               a[j] = a[j + 1];
               a[j + 1] = temp;
            }
        }
    }
}
int bin_search(int a[],int n,int target)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (a[mid] == target)
            return mid + 1;
        else if (a[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int main()
{
    //int n;
    //cin>>n;
    //int a[n];
    //for(int &vl:a) cin>>vl;
    int n = 9;
    int a[] = {5,2,1,6,3,6,1,5,4};
    printf("array before sorting:\n");
    printarr(a,n);
    cout<<endl;
    bubbleSort(a,n);
    printf("Array after sorting:\n");
    printarr(a,n);
    int target;
    printf("Enter targeted value to search:");
    cin>>target;
    int ans = bin_search(a,n,target);
    if(ans != -1) cout<<"Targeted value Found and it's index is:"<<ans<<"(1th Base index.)"<<endl;
    else cout<<"Targeted value not found.\n"<<endl;
}
