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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node *prevv = NULL, *first = NULL, *second = NULL;
void fixBST(Node *root) // using recursion and inorder traversal
{
    if (root == NULL)
        return;
    fixBST(root->left);
    if (prevv != NULL && root->key < prevv->key)
    {
        if (first == NULL)
            first = prevv;
        second = root;
    }
    prevv = root;

    fixBST(root->right);
}
//==============================================================================================================================================================================================================

// int prev = -1, firstt = -1, secondd = -1;
// int fixBSTarray(vector<int> arr)while using array
// {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] < prev)
//         {
//             if (firstt == -1)
//                 first = prev;
//             secondd = arr[i];
//         }
//         prev = arr[i];
//     }
// }

int main()
{

    Node *root = new Node(18);
    root->left = new Node(60);
    root->right = new Node(70);
    root->left->left = new Node(4);
    root->right->left = new Node(8);
    root->right->right = new Node(80);

    inorder(root);
    cout << endl;
    fixBST(root);
    int temp = first->key;
    first->key = second->key;
    second->key = temp;
    inorder(root);

    return 0;
}