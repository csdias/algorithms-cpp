#include <iostream>

using namespace std;

struct TreeNode {
    int val{};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};

    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val): left(nullptr), right(nullptr) { val = _val; };
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) { val = _val; left = _left; right = _right; };

    TreeNode* add(TreeNode* root, int val) {
        if (root->val == 0) {
            root->val = val;
            return root;
        }

        TreeNode* node = root;
        
        while ((val < node->val && node->left != nullptr) || (val > node->val && node->right != nullptr)) {
            if (node->left != nullptr && val < node->val) {
                node = node->left;
                continue;
            }

            if (node->right != nullptr && val > node->val) 
                node = node->right;
        }

        TreeNode* newNode = new TreeNode(val);

        if (val < node->val && node->left == nullptr) {
            node->left = newNode;
        }
        else if (val > node->val && node->right == nullptr) {
            node->right = newNode;
        }

        return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* foundTree = nullptr;
        TreeNode* leftTree = nullptr;
        TreeNode* rightTree = nullptr;
        
        if (root->val == val || (root->left == nullptr && root->right == nullptr)) {
            if (root->val == val) {
                return root;
            }               
            return nullptr;
        }
        
        if (root->left != nullptr) {
            leftTree = searchBST(root->left, val); 
        }
              
        if (root->right != nullptr) {
             rightTree = searchBST(root->right, val); 
        }
        
        if (leftTree != nullptr) {
            foundTree = leftTree;
        }
        
        if (rightTree != nullptr) { 
            foundTree = rightTree;
        }
        
        return foundTree;
    }

};

int main(int argc, char* argv[]){

    TreeNode* root = new TreeNode();
    TreeNode tree;
    root = tree.add(root, 4);
    root = tree.add(root, 2);
    root = tree.add(root, 7);    
    root = tree.add(root, 1);
    root = tree.add(root, 3);
    //[4,2,7,1,3]

    root = tree.searchBST(root, 2);

}