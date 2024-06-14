#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};  

class BinaryTree{
public:
    TreeNode* root;
    BinaryTree() : root(nullptr) {}

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)return NULL;

        TreeNode* t = root->right;
        root->right = root->left;
        root->left = t;

        invertTree(root->right);
        invertTree(root->left);
        return root;
    }    
};
void inorder(TreeNode* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    BinaryTree bt;

    // Constructed BinaryTree
    /*
              10
              / \
            5   15
            / \   / \
          2   7 12  20
    */

    bt.root = new TreeNode(10);
    bt.root->left = new TreeNode(5);
    bt.root->right = new TreeNode(15);
    bt.root->left->left = new TreeNode(2);
    bt.root->left->right = new TreeNode(7);
    bt.root->right->left = new TreeNode(12);
    bt.root->right->right = new TreeNode(20);

    TreeNode* res = bt.invertTree(bt.root);
    cout << "Inverted Tree: " << endl;
    /*
               10
              /  \
            15    5
            / \   / \
          20  12 7  2
    */
    inorder(res);
    return 0;
}