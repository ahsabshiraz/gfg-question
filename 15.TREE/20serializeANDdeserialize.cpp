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

void serialize(Node *root, vector<int> &arr) // serialization
{
    if (root == NULL)
    {
        arr.push_back(-1);
        return;
    }
    else
        arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);
}
int index = 0;
Node *deserialize(vector<int> &arr)//deserialization
{
    if (index == arr.size())
        return NULL;
    int val = arr[index];
    index++;
    if (val == -1)
        return NULL;
    Node *root = new Node(val);
    root->left = deserialize(arr);
    root->right = deserialize(arr);
    return root;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    return 0;
}