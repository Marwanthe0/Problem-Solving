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
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void insert_in_BST(Node *&root, int val)
{
    if (!root)
    {
        Node *child_node = new Node(val);
        root = child_node;
        return;
    }
    if (val <= root->val)
    {
        insert_in_BST(root->left, val);
    }
    else if (val > root->val)
    {
        insert_in_BST(root->right, val);
    }
    // insert_in_BST(root->left, val);
}
void print_BST(Node *root)
{
    if (!root)
        return;
    print_BST(root->left);
    cout << root->val << " ";
    print_BST(root->right);
}
bool isAvailable(Node *root, int val)
{
    if (!root)
    {
        return false;
    }
    if (root->val == val)
        return true;
    else if (val < root->val)
    {
        return isAvailable(root->left, val);
    }
    else
        return isAvailable(root->right, val);
}
void marwan()
{
    printf("Enter list size:");
    int n;
    cin >> n;
    printf("Enter list values:\n");
    int root_value;
    cin >> root_value;
    Node *root = new Node(root_value);
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        insert_in_BST(root, x);
    }
    printf("Values in inorder: ");
    print_BST(root);
    cout << endl;
    cout << "Enter Value for search:";
    int value;
    cin >> value;
    if (isAvailable(root, value))
        cout << "This value is available in the list.\n";
    else
        cout << "This Value is not avaliable in this list.\n";
}
int main()
{
    marwan();
    return 0;
}