#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree{
public:
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    // if (root1->val != root2->val) return false;
    return (root1->val == root2->val) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
};
// Recursive Solution 
/*
The idea is to compare the value of current nodes in both trees and then go on comparing the left and right subtrees recursively.
*/

int main() {
    BinaryTree bt;

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    /*
    constructed tree 1
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    // Create another tree2 with same structure as above tree 1
    // but different values.
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(8);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);

/*
    constructed tree 2
              1
            /   \
           2     8
          / \   / \
         4   5 6   7
*/

    // Check if the two trees are identical.

    if(bt.isIdentical(root1, root2)){
        cout<<"Yes, the trees are identical";
    }
    else{
        cout<<"No, the trees are not identical";
    }

    return 0;
}
