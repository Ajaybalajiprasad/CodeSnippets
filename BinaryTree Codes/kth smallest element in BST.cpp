#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree{
private:

  void inorder(TreeNode* root, int& c, int k, int& ans){
    if(root == NULL) return; 
    inorder(root->left, c, k, ans);
    c++;  
    if(c == k) {
      ans = root->data;
      return;
    }
    inorder(root->right, c, k, ans);
  }
public:
  // Function to return the kth smallest element in the given BST
  TreeNode* root;

  BinarySearchTree() : root(NULL) {}

  int kthSmallest(TreeNode* root, int k) {
    int c = 0;
    int ans = INT_MIN;
    inorder(root, c, k, ans);
    return ans;
  }
};

void PrintInorder(TreeNode* root) {
  if(root == NULL) return;
  PrintInorder(root->left);
  cout << root->data << " ";
  PrintInorder(root->right);

}

int main() {
  BinarySearchTree bst;

/*
  Given binary Search Tree
        10
       /  \
      5    13
     / \   / \
    3   6 11 14
   / \   \
  2   4   9
  
  k = 3
  output: 4
*/

  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(13);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(2);
  root->left->left->right = new TreeNode(4);
  root->left->right = new TreeNode(6);
  root->left->right->right = new TreeNode(9);
  root->right->left = new TreeNode(11);
  root->right->right = new TreeNode(14);

  cout << "Given Binary Search Tree: "<< endl;
  PrintInorder(root);
  cout << endl;

  int k = 3;
  cout << "k: "<< k <<endl;
  int ans = bst.kthSmallest(root, k);
  cout << "Kth smallest element: " << ans << endl;

return 0;
}