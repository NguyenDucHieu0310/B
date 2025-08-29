#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        // Lưu cây con phải của nút gốc
        TreeNode* rightSubtree = root->right;
        
        // Gán cây con phải của nút gốc bằng cây con trái của nút gốc
        root->right = root->left;
        
        // Gán cây con trái của nút gốc thành nullptr
        root->left = nullptr;
        
        // Duyệt đến cuối cây con phải (nếu có) và gán nút phải của nút gốc thành cây con phải của nút cuối cùng
        flatten(root->right);
        
        // Duyệt đến cuối cây con phải ban đầu (nếu có) và gán nút phải của nút cuối cùng thành cây con phải của nút gốc ban đầu
        TreeNode* node = root;
        while (node->right) {
            node = node->right;
        }
        node->right = rightSubtree;
        
        // Tiếp tục duyệt cây con phải ban đầu (nếu có)
        flatten(rightSubtree);
    }
};
int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Create the Solution object
    Solution solution;

    // Flatten the binary tree
    solution.flatten(root);

    // Print the flattened binary tree
    TreeNode* current = root;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->right;
    }

    return 0;
}
