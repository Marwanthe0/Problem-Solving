#include<iostream>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,gcd; cin>>n;
        for(int i = 1;i < n;i++) 
        {
            if(i <= n && i*2 <= n) gcd = i;
        }
        cout<<gcd<<endl;
    }
return 0;
}