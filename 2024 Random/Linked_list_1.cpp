#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
struct Node
{
    int data;
    struct Node *next;
};
void Print_List(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "element = " << ptr->data << endl;
        ptr = ptr->next;
    }
}
struct Node *insert_last(struct Node *head, int i, int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    int x = 0;
    p = head;
    while (x != i)
    {
        p = p->next;
        x++;
    }
    p->next = temp;
    temp->next = NULL;
    return temp;
}

int main()
{
    struct Node *head;
    struct Node *second;
    // struct Node *third;
    // struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));
    // fourth = (struct Node *)malloc(sizeof(struct Node));
    // head->data = 4;
    // head->next = second;
    // second->data = 8;
    // second->next = third;
    // third->data = 56;
    // third->next = fourth;
    // fourth->data = 128;
    // fourth->next = NULL;
    printf("Enter how many elements you want to insert:");
    int n;
    cin >> n;
    int head_data, second_data;
    printf("Enter element:");
    cin >> head_data;
    printf("Enter element:");
    cin >> second_data;
    head->data = head_data;
    second->data = second_data;
    head->next = second;
    second->next = NULL;
    for (int i = 1; i < n - 1; i++)
    {
        int data;
        printf("Enter element:");
        cin >> data;
        insert_last(head, i, data);
    }
    n--;
    char c = 'y';
    while (c == 'y')
    {
        printf("Do you want to insert another element:(write y for yes and n for no)\n");
        cin >> c;
        int data;
        printf("Enter element:");
        cin >> data;
        insert_last(head, n++, data);
    }
    printf("\t\tLinked list elements are:\n");
    Print_List(head);
    return 0;
}