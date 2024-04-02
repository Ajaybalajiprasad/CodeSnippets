#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class BinarySearchTree{
public:
    TreeNode* root;
    BinarySearchTree() : root(NULL) {}

    void insert(TreeNode*& root, int val){
        if(root == NULL){
            root = new TreeNode(val);
            return;
        }
        if(val < root->data){
            insert(root->left, val);
        }
        else{
            insert(root->right, val);
        }
    }
};


void inorder(TreeNode* root){
        if(root == NULL)
            return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

int main() {

    BinarySearchTree bst;

    // constructed BinarySearchTree
    /*
            10
            / \
           5   15
          / \   / \
         2   7 12  20
    */

    bst.insert(bst.root,10);
    bst.insert(bst.root,5);
    bst.insert(bst.root,15);
    bst.insert(bst.root,2);
    bst.insert(bst.root,7);
    bst.insert(bst.root,12);
    bst.insert(bst.root,20);

    inorder(bst.root);
    // Output: 2 5 7 10 12 15 20
    cout<<endl;
return 0;
}