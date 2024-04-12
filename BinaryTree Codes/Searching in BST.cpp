#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree{
public:
    TreeNode* root;
    BinarySearchTree() : root(nullptr) {}

    TreeNode* search(TreeNode* root, int key){
        while(root!=nullptr && root->data!=key){
            if(key<root->data){
                root=root->left;
            }else{
                root=root->right;
            }
        }
        return root;
    }
};
int main() {
    BinarySearchTree bst;

/*
             5
            / \
           3   8
          / \ / \
         2  4 6  10
*/  
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);


    int key = 6;
    TreeNode* res = bst.search(root, key);
    if(res!=nullptr){
        cout<<"Key found: "<<res->data<<endl;
    }else{
        cout<<"Key not found"<<endl;
    }

return 0;
}