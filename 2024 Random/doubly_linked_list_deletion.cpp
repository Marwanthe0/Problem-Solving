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
void deleteHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        printf("Invalid deletion.\n");
    }
    if (head->next == NULL)
        delete head;
    Node *temp = head;
    head = head->next;
    delete temp;
    head->prev = NULL;
}
void deletetail(Node *&head, Node *&tail)
{
    if (tail == NULL)
        printf("Invlaid deletion.\n");
    if (tail->prev == NULL)
    {
        delete tail;
    }
    Node *temp = tail;
    tail = tail->prev;
    delete temp;
    tail->next = NULL;
}
void deletemiddle(Node *head, Node *tail, int idx)
{
    Node *temp = head;
    for (int i = 0; i < idx - 1; i++)
        temp = temp->next;
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete deleteNode;
}
int size(Node *head)
{
    int sze = 0;
    Node *temp = head;
    while (temp != NULL)
        temp = temp->next, sze++;
    return sze;
}
void marwan()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = new Node(40);
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = tail;
    tail->prev = b;
    printNode(head);
    while (1)
    {
        printf("Enter the index to delete:\n");
        int idx;
        cin >> idx;
        if (idx == -1 || size(head) == 0)
            break;
        if (idx >= size(head))
            printf("Invalid deletion.\n");
        else if (idx == 0)
            deleteHead(head, tail);
        else if (idx == size(head) - 1)
            deletetail(head, tail);
        else
            deletemiddle(head, tail, idx);
        printNode(head);
    }
}
int main()
{
    marwan();
    return 0;
}