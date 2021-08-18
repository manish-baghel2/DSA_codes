#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* insertBST(node* root, int val)
{
    if(root == NULL)
    {
        return new node(val);
    }
    if(val > root->data)
    {
        root->right = insertBST(root->right, val);
    }else if(val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    return root;
}

void inorder(node* root)
{
    if( root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int arr[] = {5, 1, 3, 4, 2, 7};
    node* root = NULL;
    root = insertBST(root, 5);
    for(int i=1;i<6;i++)
    {
        insertBST(root, arr[i]);
    }
    inorder(root);
}