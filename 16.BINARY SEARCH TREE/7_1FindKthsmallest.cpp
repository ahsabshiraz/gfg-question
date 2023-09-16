#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int data)
    {
        key = data;
        left = right = NULL;
    }
};


void printKth(Node *root, int k, int &count)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        printKth(root->left, k, count);
        count++;                     // it increases while returning
        if (count == k)              // while returning it check's this condtion
        {
            cout << root->key;
            return;
        }
        printKth(root->right, k, count);// if not then call for its right 
    }
}
int main()
{

    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    int k = 3;
    int count = 0;
    cout << "Kth Smallest: ";
    printKth(root, k, count);

    return 0;
}