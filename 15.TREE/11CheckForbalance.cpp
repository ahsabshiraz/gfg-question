// Check for balanced binary tree
#include <iostream>
#include <vector>
#include <algorithm>
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

int heigth(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(heigth(root->left), heigth(root->right)) + 1;
}

bool isBalanced(Node *root) // naive
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int lh = heigth(root->left);
    int rh = heigth(root->right);
    return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}
int isBalanced2(Node *root) // efficeint
{
    if (root == NULL)
        return 0;
    int lh = isBalanced2(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced2(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return (max(lh, rh) + 1);
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);
    root->right->right->right = new Node(201);
    root->right->right->right->left = new Node(28);

    // if (isBalanced(root))
    //     cout << "Balanced";
    cout << isBalanced2 << " ";//
    if (isBalanced2(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}