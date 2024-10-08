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
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *insertAtTail(Node *head, int val)
{
    Node *temp = head;
    Node *n = new Node(val);
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
    return head;
}
Node *insertAtHead(Node *head, int val)
{
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

Node *insertAfterValue(Node *head, int val, int firstVal)
{
    Node *temp = head;
    Node *n = new Node(val);
    while (temp->next && temp->data != firstVal)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = n;
    n->next = temp2;
    return head;
}
Node *deleteHead(Node *head)
{
    if (!head)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
Node *deleteTail(Node *head)
{
    if (!head)
        return head;
    if (!head->next)
    {
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = NULL;
    free(del);
    return head;
}
Node *deleteIndex(Node *head, int idx)
{
    Node *temp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        temp = temp->next;
        if (!temp)
            break;
    }
    Node *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return head;
}
void printlist(Node *head)
{
    Node *temp = head;
    cout << "***************" << endl;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n***************" << endl;
}

/*Main code to run*/
void marwan()
{
    int size = 0;
    Node *head = new Node(1);
    Node *a = new Node(5);
    Node *b = new Node(10);
    Node *c = new Node(15);
    Node *d = new Node(20);
    size = 5;
    // linking
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    cout << "These are the intial values in the linked list." << endl;
    printlist(head);
    while (1)
    {
        int p;
        printf("Enter 1 to insert\n2 to delete and\nanything else to exit:\n");
        cin >> p;
        if (p == 1)
        {
            printf("Enter 1 if you want to insert in an index,\n2 to insert after a value:\n");
            int op;
            cin >> op;
            if (op == 1)
            {
                printf("Enter index and value to insert:\n");
                int idx, data;
                cin >> idx >> data;
                if (idx == size)
                {
                    head = insertAtTail(head, data);
                }
                else if (idx == 0)
                {
                    head = insertAtHead(head, data);
                }
                else if (idx >= size)
                {
                    cout << "You inserted the wrong index to input." << endl;
                }
                else
                {
                    head = insertAtIndex(head, data, idx);
                }
                size++;
            }
            else if (op == 2)
            {
                printf("Enter value after which you want to insert data and the targeted data:\n");
                int firstVal, data;
                cin >> firstVal >> data;
                head = insertAfterValue(head, data, firstVal);
                size++;
            }
            else
            {
                cout << "You inserted the wrong operator." << endl;
                break;
            }
        }
        else if (p == 2)
        {
            int idx;
            printf("Enter index to delete:\n");
            cin >> idx;
            if (idx == 0)
            {
                head = deleteHead(head);
            }
            else if (idx == size - 1)
            {
                head = deleteTail(head);
                size--;
            }
            else if (idx > 0 && idx < size)
            {
                head = deleteIndex(head, idx);
                size--;
            }
            else
            {
                cout << "You inserted the wrong operator.\n";
            }
        }
        else
            break;
        printlist(head);
    }
}
int main()
{
    marwan();
    return 0;
}
