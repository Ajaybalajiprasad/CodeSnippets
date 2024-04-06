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
    // Insert a new node with the given key
    TreeNode* insert(TreeNode* root, int key) {;
        TreeNode* cur = root;
        if (cur == NULL) {
            return new TreeNode(key);
        }
        if (key < cur->data) {
            cur->left = insert(cur->left, key);
        } else {
            cur->right = insert(cur->right, key);
        }
        return root;
    }
    // Inorder traversal of the BST
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};


int main() {
    BinarySearchTree bst;

/* Constructed tree is
        1
       / \
      2   4
         /  \
        3    5
              \
               6 
*/
    TreeNode *root = new TreeNode (1);
    root->left = new TreeNode (2);
    root->right = new TreeNode (4);
    root->right->left = new TreeNode (3);
    root->right->right = new TreeNode (5);
    root->right->right->right = new TreeNode (6);
    root = bst.insert(root, 7);

    // Print the inorder traversal of the BST
    cout << "Inorder traversal of the BST:\n";
    bst.inorder(root);

    return 0;
}