//Correct but not efficient

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int maxValue(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    int res = root->key;
    int lres = maxValue(root->left);
    int rres = maxValue(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int minValue(Node *root)
{
    if (root == NULL)
        return INT_MAX;

    int res = root->key;
    int lres = minValue(root->left);
    int rres = minValue(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}
int isBST(Node *root)
{
    if (root == NULL)
        return 1;

    if (root->left != NULL && maxValue(root->left) > root->key)
        return 0;

    if (root->right != NULL && minValue(root->right) < root->key)
        return 0;
    
    if (!isBST(root->left) || !isBST(root->right))
        return 0;

    return 1;
}

int main()
{

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(18);
    root->right->right = new Node(35);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}