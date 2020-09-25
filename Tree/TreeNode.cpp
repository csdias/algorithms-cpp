#include <iostream>

using namespace std;

struct TreeNode {
    int val{};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};

    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val): left(nullptr), right(nullptr) { val = _val; };
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) { val = _val; left = _left; right = _right; };
};
