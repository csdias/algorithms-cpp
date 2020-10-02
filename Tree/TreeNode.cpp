#include <iostream>
#include <queue>
#include <stack>

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

    vector<int> levelOrderSort(TreeNode* root) {
        TreeNode* node = root;
        TreeNode* left{};
        TreeNode* right{};
        std::queue<TreeNode*> q{};
        vector<int> vi{};

        q.push(node);

        while(q.size() > 0) {
            node = q.front();
            vi.push_back(node->val);
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
            q.pop();
        }

        for(int a : vi) {
            std::cout << a << " ";
        }

        return vi;
    }

    TreeNode* inOrderSort(TreeNode* root) {
        TreeNode* left{};
        TreeNode* right{};
        std::vector<int> vi{};

        if (root->left == nullptr && root->right == nullptr)
            return root;

        if (root->left != nullptr) {
            left = inOrderSort(root->left);
        };

        if (left != nullptr) 
            vi.push_back(left->val);
        
            vi.push_back(root->val);

        if (root->right != nullptr) {
            right = inOrderSort(root->right);
        };

        if (right != nullptr)
        vi.push_back(right->val);

    }

    vector<int> sort(TreeNode* root) {
        TreeNode* next;
        std::queue<TreeNode*> q{};
        std::vector<int> vi{};

        q.push(root->left);
        while(q.size() > 0) {
            next = q.front();
            vi.push_back(next->val);
            if (next->left!=nullptr) q.push(next->left);
            if (next->right!=nullptr) q.push(next->right);

            q.pop();
        }
        vi.push_back(root->val);
        q.push(root->right);
        while(q.size() > 0) {
            next = q.front();
            vi.push_back(next->val);
            if (next->left != nullptr) q.push(next->left);
            if (next->right != nullptr) q.push(next->right); 
            q.pop();
        }

        return vi;
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
    //[3,2,1,5,4,7]

    vector<int> vi = tree.levelOrderSort(root);
     for(int a: vi) {
         std::cout << a << " ";
    }

    //auto a = tree.levelOrderSort(root)

    root = tree.searchBST(root, 2);

};