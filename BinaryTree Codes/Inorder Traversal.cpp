#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* right;
    TreeNode* left;


    TreeNode(int val) : data(val),right(NULL),left(NULL){};
};

class BinaryTree{
public:
    TreeNode* root = nullptr;

    BinaryTree() : root(nullptr) {};

    void inorder(TreeNode* root){
        if(root == NULL) return ;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BinaryTree bt;

    bt.root = new TreeNode(1);
    bt.root -> left = new TreeNode(2);
    bt.root -> right = new TreeNode(3);
    bt.root -> left -> left  = new TreeNode(4);
    bt.root -> left -> right  = new TreeNode(5);
    bt.root -> right -> left = new TreeNode(6);
    bt.root -> right -> right = new TreeNode(7);

    cout<<" Inorder Traversal : ";
    bt.inorder(bt.root);
    cout<<endl;

return 0;
}

