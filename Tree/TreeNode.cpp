#include <iostream>

using namespace std;

struct TreeNode {
    int val{};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};

    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val): left(nullptr), right(nullptr) { val = _val; };
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) { val = _val; left = _left; right = _right; };

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* foundTree = nullptr;
        TreeNode* leftTree = nullptr;
        TreeNode* rightTree = nullptr;
        
        if (root->val == val || (root->left == nullptr && root->right == nullptr)) {
            if (root->val == val) {
                foundTree = root;
            }               
            
            return foundTree;
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

    TreeNode tn;
    TreeNode* t;

    //[4,2,7,1,3]

    TreeNode* tree = tn.searchBST(t, 2);

}
