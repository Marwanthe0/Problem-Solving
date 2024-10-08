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
Node *insertAtTail(Node *head, int val)
{
    if(head == NULL)
    {
        Node *n = new Node(val);
        head = n;
        return head;
    }
    else{
    Node *temp = head;
    Node *n = new Node(val);
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
    return head;
    }
}
Node *insertAtHead(Node *head, int val)
{
    if(!head)
    {
    Node *n = new Node(val);
    head = n;
    return head;
    }
    Node *n = new Node(val);
    Node *tmp = head;
    n->next = head;
    head = n;
    return head;
}

Node *insertAtIndex(Node *head, int val, int idx)
{
    idx--;
    Node *n = new Node(val);
    Node *tmp = head;
    Node *tmp2 = NULL;
    for (int i = 0; i < idx; i++)
    {
        tmp = tmp->next;
    }
    tmp2 = tmp->next;
    tmp->next = n;
    n->next = tmp2;
    return head;
}
int indextoinsert(Node * head,int val)
{
    if(head == NULL)
    {
        return 0;
    }
    Node * temp = head;
    int idx = 1;
    if(temp->next == NULL)
    {
        if(val > temp->val) return 1;
        else return 0;
    }
    if(val < temp->val) return 0;
    while(temp->next)
    {
        int x = temp->next->val;
        if(x >= val) return idx;
        temp = temp->next;
        idx++;
    }
    return idx;
}
int main()
{
    printf("Enter list size:");
    int n,size = 0;
    cin>>n;
    if(n == 0) return 0;
    cout<<"Enter list values:\n";
    Node * head = NULL;
    while(n--)
    {
        int val;
        cin>>val;
        int idx = indextoinsert(head,val);
                if (idx == size)
                {
                    head = insertAtTail(head, val);
                }
                else if (idx == 0)
                {
                    head = insertAtHead(head, val);
                }
                else
                {
                    head = insertAtIndex(head, val, idx);
                }
                size++;
            printlist(head);
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
