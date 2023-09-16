//Constructing a binary tree from a preorder and inorder traversal
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int a)
    {
        key = a;
        left = right = NULL;
    }
};

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  

//========================
int preorder = 0;
Node *cTree(int pre[], int in[], int is, int ie) // is=inoderStart,ie=inorderEnd//to get the left and rigth child if they exits
{
    if (is > ie)
        return NULL;
    Node *root = new Node(pre[preorder++]);
    int inIndex;
    for (int i = is; i <= ie; i++)
    {
        if (root->key == in[i])
        {
            inIndex = i;
            break;
        }
    }
    root->left = cTree(pre, in, is, inIndex - 1);
    root->right = cTree(pre, in, inIndex + 1, ie);
    return root;
}

int main() {
	
	int in[]={20,10,40,30,50};
	int pre[]={10,20,30,40,50};
	int n=sizeof(in)/sizeof(in[0]);
	Node *root=cTree(in, pre, 0, n-1);
	inorder(root);
}