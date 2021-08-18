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


// my attempt on level traversal
// queue<int> q;

// void level_traversal(struct node* root)
// {
//     cout<<"does this run"<<endl;
//     if(root == NULL)
//     {
//         return;
//     }
//     q.push(root->left->data);
//     cout<<q.front()<<endl;;
//     q.push(root->right->data);
//     cout<<q.front()<<endl;
//     level_traversal(root->left);
//     level_traversal(root->right);
// }

void level_sum(node* root, int k)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int l=1, sum=0;
    while(!q.empty())
    {
        node* n = q.front();
        q.pop();
        if(n != NULL)
        {
            sum+=n->data;
            if(n->left)
            {
                q.push(n->left);
            }
            if(n->right)
            {
                q.push(n->right);
            }
        }else if(!q.empty())
        {
            if(l == k)
            {
                cout<<sum;
                return;
            }
            sum=0;
            l=l+1;
            q.push(NULL);
        }else if(l==k)
        {
            cout<<sum;
            return;
        }
    }
}

// void level_traversal2(struct node* root)
// {
//     if(root == NULL)
//     {
//         return;
//     }
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty())
//     {
//         node* n = q.front();
//         q.pop();
//         if(n!=NULL)
//         {
//             cout<<n->data<<" ";
//             if(n->left)
//                 q.push(n->left);
//             if(n->right)
//                 q.push(n->right);
//         }else if(!q.empty())
//         {
//             q.push(NULL);
//         }
//     }
// }

int countnodes(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return countnodes(root->left)+countnodes(root->right)+root->data;
}

int returnheight(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return max(returnheight(root->left),returnheight(root->right))+1;
}

int diameter(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lheight = returnheight(root->left);
    int rheight = returnheight(root->right);
    int currdiameter = lheight+rheight+1;

    int rdiameter = diameter(root->right);
    int ldiameter = diameter(root->left);
    return max(currdiameter, max(rdiameter, ldiameter));
}

int diameter2(node* root, int *h)
{
    if(root == NULL)
    {
        *h = 0;
        return 0;
    }
    int lh=0, rh=0;
    int ld = diameter2(root->left, &lh);
    int rd = diameter2(root->right, &rh);
    int currdiamter = lh+rh+1;
    *h = max(lh,rh)+1;
    return max(currdiamter, max(ld, rd));
}

//my approach for changing the value of current node with the sum of the subsequent tree and its value
// int sumreplace(node* root)
// {
//     if(root == NULL)
//     {
//         return 0;
//     }
//     root->data = root->data + sumreplace(root->left)+sumreplace(root->right);
//     return root->data;
// }

void sumreplace(node* root)
{
    if(root == NULL)
    {
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);
    if(root->left !=NULL)
    {
        root->data += root->left->data;
    }
    if(root->right != NULL)
    {
        root->data += root->right->data;
    }
}

bool heightbalance(node* root)
{
    if(root == NULL)
    {
        return true;
    }
    if(heightbalance(root->left) == false)
    {
        return false;
    }
    if(heightbalance(root->right) == false)
    {
        return false;
    }
    int lh = returnheight(root->left), rh = returnheight(root->right);
    if(abs(lh-rh) <= 1)
    {
        return true;
    }else{
        return false;
    }
}

bool heightbalance2(node* root, int *h)
{
    if(root == NULL)
    {
        return true;
    }
    int lh=0, rh=0;
    if(heightbalance2(root->left, &lh) == false)
    {
        return false;
    }
    if(heightbalance2(root->right, &rh) == false)
    {
        return false;
    }
    *h = max(lh, rh)+1;
    if(abs(lh-rh) <= 1)
    {
        return true;
    }else{
        return false;
    }
}

void rightview(node* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            node* curr = q.front();
            q.pop();
            if(i==0)
            {
                cout<<curr->data<<" ";
            }
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }
            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

bool getpath(node* root, int k, vector<int> &path)
{
    if(root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if(root->data == k)
    {
        return true;
    }
    if(getpath(root->left, k, path) || getpath(root->right, k, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(node* root, int n1, int n2)
{
    vector<int> path1, path2;
    if(!getpath(root, n1, path1 ) || !getpath(root, n2, path2))
    {
        return -1;
    }

    int pc;
    for(pc=0;pc< path1.size() and pc < path2.size() ; pc++)
    {
        if(path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
}

node* lca2(node* root, int n1, int n2)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == n1 || root->data == n2)
    {
        return root;
    }
    node* leftlca = lca2(root->left, n1, n2);
    node* rightlca = lca2(root->right, n1,n2);
    if(leftlca and rightlca)
    {
        return root;
    }
    if(leftlca != NULL)
    {
        return leftlca;
    }
    return rightlca;
}

int shortpath(node* root, int n1, int n2)
{
    node* lca = lca2(root, n1, n2);
    vector<int> path1, path2;
    getpath(lca, n1, path1);
    getpath(lca, n2, path2);
    int ans = path1.size() + path2.size() -2 ;
    return ans;
}

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    // root->left->right = new node(5);
    root->right->left = new node(5);
    root->right->left->left = new node(6);
    root->right->right = new node(7);
    // cout<<"this is preorder traversal"<<endl;
    // preorder(root);
    // cout<<endl<<"this is inorder traversal"<<endl;
    // inorder(root);
    // cout<<endl<<"this is postorder traversal"<<endl;
    // postorder(root);

    // program to make a tree from  preorder and inorder arrays of the tree 
    // int preord[] = {1, 2, 4, 5, 3, 6, 7};
    // int inord[] = {4, 2, 5, 1, 6, 3, 7};
    // node* n = root(preord, inord, 0, 6);
    // inorder(n);
    // level_traversal(root);
    // while(!q.empty())
    // {
    //     cout<<q.front();
    //     q.pop();
    // }
    // level_traversal2(root);
    // level_sum(root, 1);
    // cout<<countnodes(root);
    // cout<<returnheight(root);
    // int h=0;
    // cout<<diameter2(root, &h);
    // sumreplace(root);
    // preorder(root);
    // int h=0;
    // if(heightbalance2(root, &h)==true)
    // {
    //     cout<<"it is balanced";
    // }else{
    //     cout<<"it is not balanced";
    // }
    // rightview(root);
    // cout<<LCA(root, 5, 7);
    // cout<<lca2(root, 3, 5)->data;
    cout<<shortpath(root, 5, 3);
}