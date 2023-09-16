#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
Node *getsuccessor(Node *root)
{
    Node *curr = root->right;
    while (curr != NULL and curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node *delNode(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->key > x)
        root->left = delNode(root->left, x);
    else if (root->key < x)
        root->right = delNode(root->right, x);
    else
    {
        if (root->left == NULL) // when the node to be deleted has only one child// it also handles the case where node has no child
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) // when the node to be deleted as only one child// it also handles the case where node has no child
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else // when the node to be deleted has both the child
        {
            Node *succ = getsuccessor(root);               // we find a successor
            root->key = succ->key;                         // copy succ->value to the curr node which going to be deleted
            root->right = delNode(root->right, succ->key); // and call to delete the succ->key bcz node is duplicate
        }                                                  // succ is always in root's right child's left most child node
    }
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 15;

    root = delNode(root, x);
    inorder(root);
    return 0;
}