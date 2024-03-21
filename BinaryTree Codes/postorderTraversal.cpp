#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), right(nullptr), left(nullptr) {};
};

class BinaryTree{
public:

    void PostOrder(TreeNode* root){
        if(root==nullptr)return;
        
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
};

int main() {
    BinaryTree bt;

    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> left -> right -> left = new TreeNode(8);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    root -> right -> right -> left = new TreeNode(9);
    root -> right -> right -> right = new TreeNode(10);


    cout<<"PostOrder Traversal : ";
    bt.PostOrder(root);
    cout<<endl;

return 0;
}