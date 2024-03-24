#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

// Driver code to test the above functions
int main() {
    /* Constructed tree is
        1
       / \
      2   3
         /  \
        4    5
            /  
           6    
*/
    TreeNode *root = new TreeNode (1);
    root->left = new TreeNode (2);
    root->right = new TreeNode (3);
    root->right->left = new TreeNode (4);
    root->right->right = new TreeNode (5);
    root->right->right->left = new TreeNode (6);

    // Function call
    cout << "Maximum depth of the tree is " << maxDepth(root) << endl;

    return 0;
}
