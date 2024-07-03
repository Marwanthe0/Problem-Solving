#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void inserttail(Node *&head, Node *&tail, int data)
{
    Node *NewNode = new Node(data);
    if (head == NULL)
    {
        head = tail = NewNode;
        return;
    }
    tail->next = NewNode;
    NewNode->prev = tail;
    tail = NewNode;
}
void printNode(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
bool isequal(Node *head, Node *head2)
{
    Node *tmp1 = head;
    Node *tmp2 = head2;
    while (tmp1 != NULL && tmp2 != NULL)
    {
        if (tmp1->data != tmp2->data)
        {
            return false;
        }
        tmp1 = tmp1->next, tmp2 = tmp2->next;
    }
    if (tmp1 != NULL || tmp2 != NULL)
        return false;
    return true;
}
void marwan()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    while (1)
    {
        int data;
        cin >> data;
        if (data == -1)
            break;
        inserttail(head1, tail1, data);
    }
    while (1)
    {
        int data;
        cin >> data;
        if (data == -1)
            break;
        inserttail(head2, tail2, data);
    }
    if (isequal(head1, head2))
        yes;
    else
        no;
}
int main()
{
    marwan();
    return 0;
}