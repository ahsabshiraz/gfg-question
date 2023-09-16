#include <bits/stdc++.h>
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
void inorder(Node *root)
{
          if (root != NULL)
          {
                    inorder(root->left);
                    cout << root->key << " ";
                    inorder(root->right);
          }
}

void fun(Node *root)
{
          map<int, int> mp;
          queue<pair<Node *, int>> q;
          q.push({root, 0});
          while (q.empty() == false)
          {
                    Node *root = q.front().first;
                    int hd = q.front().second;
                    if (mp.find(hd) == mp.end())
                              mp[hd] = root->key;
                    q.pop();
                    if (root->left)
                              q.push({root->left, hd - 1});
                    if (root->right)
                              q.push({root->right, hd + 1});
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
          // root = fun(root, x);
          inorder(root);
          return 0;
}