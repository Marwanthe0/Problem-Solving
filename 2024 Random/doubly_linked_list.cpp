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
void insertatmiddle(Node *head, int data, int idx)
{
    Node *NewNode = new Node(data);
    Node *temp = head;
    for (int i = 0; i < idx - 1; i++)
        temp = temp->next;
    NewNode->next = temp->next;
    NewNode->next->prev = NewNode;
    temp->next = NewNode;
    NewNode->prev = temp;
}
void insertHead(Node *&head, Node *&tail, int data)
{
    Node *NewNode = new Node(data);
    if (head == NULL)
    {
        head = NewNode;
        tail = NewNode;
        return;
    }
    NewNode->next = head;
    head->prev = NewNode;
    head = NewNode;
}
void insertTail(Node *&head, Node *&tail, int data)
{
    Node *NewNode = new Node(data);
    if (head == NULL)
    {
        head = NewNode;
        tail = NewNode;
        return;
    }
    tail->next = NewNode;
    NewNode->prev = tail;
    tail = NewNode;
}
void deleteHead(Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
        return;
    else if (head == tail)
    {
        head = tail = NULL;
        return;
    }
    Node *del = head;
    head = head->next;
    head->prev = NULL;
    free(del);
}
void deleteTail(Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
        return;
    else if (head == tail)
    {
        head = tail = NULL;
        return;
    }
    Node *del = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(del);
}
void deleteIndex(Node *&head, Node *&tail, int idx)
{
    if (head == NULL && tail == NULL)
        return;
    else if (head == tail)
    {
        head = tail = NULL;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    free(del);
}
// int size(Node *head)
// {
//     int sze = 0;
//     Node *temp = head;
//     while (temp != NULL)
//         temp = temp->next, sze++;
//     return sze;
// }
void marwan()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = new Node(40);
    int size = 4;
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = tail;
    tail->prev = b;
    printNode(head);
    while (1)
    {
        int p;
        printf("Enter 1 to insert,\n2 to delete and\n anything else to break:\n");
        cin >> p;
        if (p == 1)
        {
            printf("Insert an index and a data:");
            int data, idx;
            cin >> idx >> data;
            if (data == -1)
                break;
            if (idx > size)
            {
                printf("Invalid insertion\n");
                size--;
            }
            else if (idx == 0)
            {
                insertHead(head, tail, data);
            }
            else if (idx == size)
            {
                insertTail(head, tail, data);
            }
            else
            {
                insertatmiddle(head, data, idx);
            }
            size++;
        }
        else if (p == 2)
        {
            printf("Insert index to delete:");
            int idx;
            cin >> idx;
            if (idx == 0)
            {
                deleteHead(head, tail);
            }
            else if (idx == size - 1)
            {
                deleteTail(head, tail);
            }
            else if (idx > 0 && idx < size - 1)
            {
                deleteIndex(head, tail, idx);
            }
            size--;
        }
        else
            break;
        printf("After insertion\n");
        printNode(head);
    }
}
int main()
{
    marwan();
    return 0;
}