#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
class linked_list
{
public:
    int data;
    linked_list *next;
};
void insert_element(linked_list *head, int data)
{
    linked_list *temp = new linked_list;
    temp->data = data;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
    temp->next = NULL;
}
void insert_middle_element(linked_list *head, int data, int idx)
{
    linked_list *temp = new linked_list;
    temp->data = data;
    linked_list *p = head;
    int x = 0;
    while (x != idx)
    {
        p = p->next;
        x++;
    }
    temp->next = p->next;
    p->next = temp;
}
void print_list(linked_list *head)
{
    linked_list *p = head;
    while (p->next != NULL)
    {
        cout << "Element:" << p->data << endl;
        p = p->next;
    }
    cout << "Element:" << p->data << endl;
}
void marwan()
{
    linked_list *head = new linked_list;
    printf("Do you want to insert an element(enter y = for yes and anything for no):");
    char c;
    cin >> c;
    if (c == 'y')
    {
        int n;
        printf("Enter the Element:");
        cin >> n;
        head->data = n;
        head->next = NULL;
        while (1)
        {
            printf("Do you want to enter another elemnet(enter y = for yes,m for insertion at middle,p for printing the linked list and anything for no):");
            char c_1;
            cin >> c_1;
            if (c_1 == 'y')
            {

                printf("Enter the Element:");
                int data;
                cin >> data;
                insert_element(head, data);
            }
            else if (c_1 == 'm')
            {
                printf("Enter the index to insert:");
                int idx;
                cin >> idx;
                printf("Enter the Element:");
                int data;
                cin >> data;
                insert_middle_element(head, data, idx);
            }
            else if (c_1 == 'p')
                print_list(head);
            else
                break;
        }
    }
    else
        return;
}
int main()
{
    marwan();
    return 0;
}