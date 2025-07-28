#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
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

int findMaxDistance(map<Node *, Node *> &mpp, Node *target)
{
    queue<Node *> q;
    q.push(target);
    map<Node *, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0; // flage
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left and !vis[node->left])
            {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right and !vis[node->right])
            {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if (mpp[node] and !vis[mpp[node]]) // curr nodes parent
            {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (fl)
            maxi++;
    }
    return maxi;
}

Node *bfsToMapParents(Node *root, map<Node *, Node *> &mpp, int start)
{
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (q.empty() == false)
    {
        Node *node = q.front();
        if (node->key == start)
            res = node;
        q.pop();
        if (node->left)
        {
            mpp[node->left] = node; // currNode->parentNode
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
        return res;
}

int timeToBurnTree(Node *root, int start)//TC-O(N)
{
    map<Node *, Node *> mpp;
    Node *target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(8);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(10);
    root->left->right->left->left = new Node(11);
    cout << timeToBurnTree(root, 11);
    return 0;
}