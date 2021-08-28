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

node* search(node* root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == val)
    {
        return root;
    }

    if(val > root->data)
    {
        return search(root->right, val);
    }else if(val < root->data)
    {
        return search(root->left, val);
    }
}

node* searchBST(node* root, int k)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == k )
    {
        return root;
    }
    if(root->data > k)
    {
        return searchBST(root->left, k);
    }
    if(root->data < k)
    {
        return searchBST(root->right, k);
    }
}

node* inordersucc(node* root)
{
    node* temp = root;
    while(temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node* deleteBST(node* root, int k)
{
    if(k < root->data)
    {
        root->left = deleteBST(root->left, k);
    }else if(k > root->data)
    {
        root->right = deleteBST(root->right, k);
    }else 
    {
        if(root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        
        node* temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
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
    cout<<endl;
    // cout<<search(root, 1)->data;
    // if(searchBST(root, 4) == NULL)
    // {
    //     cout<<" this doesnt exist in the BST";
    // }else{
    //     cout<<" this exists in the BST";
    // }
    inorder(root);
    cout<<endl;
    deleteBST(root, 3);
    inorder(root);
}