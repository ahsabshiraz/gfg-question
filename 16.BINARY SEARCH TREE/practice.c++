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

void vTraversal(Node *root)
{
    map<int, int> mp;
    queue<pair<int, Node *>> q;
    q.push({0, root});
    while (q.empty() == false)
    {
        int hd = q.front().first;
        Node *curr = q.front().second;
        q.pop();

        mp[hd] = curr->key;

        if (curr->left)
            q.push({hd - 1, curr->left});
        if (curr->right)
            q.push({hd + 1, curr->right});
    }
    for (auto x : mp)
        cout << x.second << " ";

    cout << endl;
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    vTraversal(root);

    return 0;
}