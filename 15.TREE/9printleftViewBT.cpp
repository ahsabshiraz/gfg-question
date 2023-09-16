// print left view of binary tree
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        right = left = NULL;
    }
};
int currlevel = 0;
void printLeft1(Node *root, int level)
{
    if (root == NULL)
        return;
    if (currlevel < level)
    {
        cout << root->key << " ";
        currlevel = level;
    }
    printLeft1(root->left, level + 1);
    printLeft1(root->right, level + 1);
}

void printLeftView(Node *root) // method-1
{
    printLeft1(root, 1);
}

//================================================================

void printLeft2(Node *root) // method-2
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    printLeftView(root);
    cout<<" \n";
    printLeft2(root);
    return 0;
}