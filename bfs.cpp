#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printBFS(TreeNode* root) {
    if(root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0 ; i < sz ; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout<<node->val<<" ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    cout<<endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    printBFS(root);
    return 0;
}