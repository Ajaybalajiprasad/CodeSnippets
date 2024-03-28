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

    int diameter(TreeNode* root){
        int maxi = 0;
        height(root, maxi);
        return maxi;
    }

    int height(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int lh = height(root->left, maxi);
        int rh = height(root->right, maxi);

        maxi = max(maxi, lh+rh);

        return 1 + max(lh,rh);
    }
};
// Driver code to test the above functions
int main() {

/*
created Binary tree
      1  
     / \
    2   3
       / \
      4   6
     /     \
    5       7
   /         \
  9           8
*/
    BinaryTree bt;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    root->right->right->right->right = new TreeNode(8);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(5);
    root->right->left->left->left = new TreeNode(9);

    cout << "Diameter of given binary tree is " << bt.diameter(root) << endl;

return 0;
}
