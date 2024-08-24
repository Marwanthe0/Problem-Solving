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
int maxh(Node *root)
{
    if (!root)
        return 0;
    int l = maxh(root->left);
    int r = maxh(root->right);
    return max(l, r) + 1;
}
int rootcount(Node *root)
{
    if (!root)
        return 0;
    return rootcount(root->left) + rootcount(root->right) + 1;
}
int leafcount(Node *root)
{
    if (!root)
        return 0;
    int left = leafcount(root->left);
    int right = leafcount(root->right);
    if (left == 0 && right == 0)
        return 1;
    else
        return left + right;
}
void levelorder(Node *root)
{
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cout << f->val << " ";
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void marwan()
{
    int frst;
    cin >> frst;
    Node *root = new Node(frst);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        if (l != -1)
        {
            Node *lft = new Node(l);
            f->left = lft;
            q.push(f->left);
        }
        if (r != -1)
        {
            Node *rght = new Node(r);
            f->right = rght;
            q.push(f->right);
        }
    }
    levelorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    cout << "Number of nodes are:" << rootcount(root) << endl;
    cout << "Number of leaf nodes are:" << leafcount(root) << endl;
    cout << "Maximum height is:" << maxh(root) << endl;
}
int main()
{
    marwan();
    return 0;
}