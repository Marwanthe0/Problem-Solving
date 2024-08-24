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
void pre_order(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}
void level_order(Node *root)
{
    queue<Node *> q;
    if (!root)
        cout << "No root found\n";
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cout << f->val << " ";
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
void marwan()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        // Kaj
        int l, r;
        cin >> l >> r;
        // left right connect
        if (l != -1)
        {
            Node *left = new Node(l);
            f->left = left;
            q.push(left);
        }
        if (r != -1)
        {
            Node *right = new Node(r);
            f->right = right;
            q.push(right);
        }
    }
    level_order(root);
    cout << endl;
    pre_order(root);
}
int main()
{
    marwan();
    return 0;
}