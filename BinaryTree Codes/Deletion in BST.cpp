#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), right(nullptr), left(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;
    BinarySearchTree() : root(nullptr) {}

    TreeNode* deleteNode(TreeNode*& root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->data == key) {
            return helper(root);
        }

        TreeNode* save = root;
        while (root != NULL) {
            if (root->data > key) {
                if (root->left != NULL && root->left->data == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->data == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return save;
    }

// Helper function to delete a node from BST
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr) {
            return root->right;
        } else if (root->right == nullptr) {
            return root->left;
        }
        TreeNode* right = root->right;
        TreeNode* lastRight = findLast(root->left);
        lastRight->right = right;
        return root->left;
    }

    TreeNode* findLast(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    // To print the tree
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    /* constructed Binary Tree
                10
               / \
              5   15
             / \  / \
            2   7 12 20
    */
    BinarySearchTree bst;

    bst.root = new TreeNode(10);
    bst.root->left = new TreeNode(5);
    bst.root->right = new TreeNode(15);
    bst.root->left->left = new TreeNode(2);
    bst.root->left->right = new TreeNode(7);
    bst.root->right->left = new TreeNode(12);
    bst.root->right->right = new TreeNode(20);

    cout<<"Before deleting 10: ";
    bst.inorder(bst.root);
    cout << endl;

    cout<<"After deleting 10: ";
    // 2 5 7 12 15 20"
    bst.root = bst.deleteNode(bst.root, 10); // Deleting node with key 10
    bst.inorder(bst.root);
    cout << endl;

    return 0;
}
