#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree{
public:
    TreeNode *root;
    BinaryTree() : root(nullptr) {}

    int maximumPathSum(TreeNode *root, int &maxi){
        if(root == nullptr) return 0;

        int leftSum = max(0,maximumPathSum(root->left,maxi));
        int rightSum = max(0,maximumPathSum(root->right,maxi));

        maxi = max(maxi, leftSum + rightSum + root->val);

        return max(leftSum, rightSum) + root->val;
    }


    int ans(TreeNode* root){
        int maxi = INT_MIN;
        maximumPathSum(root, maxi);
        return maxi;
    }
    
};
int main() {

    BinaryTree bt;
/*constructed BT
       -10
      /   \
     9    20
          /  \
         15   7
*/

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    int res = bt.ans(root);
    cout << "Maximum Path Sum: " << res << endl;
    //ans is 42
return 0;
}