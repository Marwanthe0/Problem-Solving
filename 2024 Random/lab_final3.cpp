#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node * next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void printlist(Node * head)
{
    Node * temp = head;
    while(temp)
    {
        cout<<temp->val<<" "
        ;
        temp = temp->next;
    }
    cout<<endl;
}
int searchlist(Node * head,int target)
{
    Node * temp = head;
    int idx = 0;
    while(temp)
    {
        if(temp->val == target) return idx;
        else temp = temp->next;
        idx++;
    }
    return -1;
}
int main()
{
    printf("Enter list size:");
    int n;
    cin>>n;
    cout<<"Enter list values:\n";
    if(!n) return 0;
     int val;
     cin>>val;
    Node * head = new Node(val);
    Node * temp = head;
    n--;
    while(n--)
    {
        int val;
        cin>>val;
        Node * n = new Node(val);

        temp->next = n;
        temp = temp->next;
    }
    printf("The list is:\n");
    printlist(head);
    printf("Enter targeted value to search:");
    int target;
    cin>>target;
    int ans = searchlist(head,target);
    if(ans == -1) cout<<"Targeted Vaue not found.\n";
    else cout<<"Found at position no:"<<ans + 1<<endl;
}

