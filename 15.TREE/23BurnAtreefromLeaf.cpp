// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node
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

int res = 0;

// Function to find the time for the tree to burn
int burnTime(Node *root, int leaf, int &dist)
{
    if (root == NULL)
        return 0;
    if (root->key == leaf)
    {
        dist = 0;
        return 1; // bcz we know it is a leaf node
    }
    int ldist = -1, rdist = -1;
    int lh = burnTime(root->left, leaf, ldist);
    int rh = burnTime(root->right, leaf, rdist);

    if (ldist != -1)
    {
        dist = ldist + 1;          // only for ancestors
        res = max(res, dist + rh); // adding the distance of curr node from leaf with its righthieght
    }
    else if (rdist != -1)
    {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }
    return max(lh, rh) + 1;
}

// Driver code
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    int dist = -1;
    int target = 2;
    burnTime(root, target, dist);
    cout << res;
    return 0;
}
