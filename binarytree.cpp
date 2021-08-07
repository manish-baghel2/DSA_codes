#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int search(int inord[], int start, int end, int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(curr = inord[i])
        {
            return i;
        }
    }
    return -1;
}

 node* root(int preform[], int inform[], int start, int end)
{
    static int idx = 0;
    if(start>end)
    {
        return NULL;
    }
    int curr = preform[idx];
    idx++;
    node* n = new node(curr);
    if(start==end)
    {
        return n;
    }
    int pos = search(inform, start, end, curr);
    n->left = root(preform, inform, start, pos-1);
    n->right = root(preform, inform, pos+1, end);

    return n;
}

int main()
{
    // struct node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    // cout<<"this is preorder traversal"<<endl;
    // preorder(root);
    // cout<<endl<<"this is inorder traversal"<<endl;
    // inorder(root);
    // cout<<endl<<"this is postorder traversal"<<endl;
    // postorder(root);

    // program to make a tree from  preorder and inorder arrays of the tree 
    int preord[] = {1, 2, 4, 5, 3, 6, 7};
    int inord[] = {4, 2, 5, 1, 6, 3, 7};
    node* n = root(preord, inord, 0, 6);
    inorder(n);
}