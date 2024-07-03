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
void reverse(Node *&head, Node *&tail)
{
    Node *i = head;
    Node *j = tail;
    while (i != j && j != i->next)
    {
        swap(i->data, j->data);
        i = i->next;
        j = j->prev;
    }
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
void marwan()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (1)
    {
        int data;
        cin >> data;
        if (data == -1)
            break;
        inserttail(head, tail, data);
    }
    reverse(head, tail);
    printNode(head);
}
int main()
{
    marwan();
    return 0;
}