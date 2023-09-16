// Creating a binary tree
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
int res = 0;
int fun(Node *root)
{
          if (!root)
                    return root;
          int lh = fun(root->left);
          int rh = fun(root->right);
          res = max(res, lh + rh + 1);
          return 1 + max(lh + rh);
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
          return 0;
}