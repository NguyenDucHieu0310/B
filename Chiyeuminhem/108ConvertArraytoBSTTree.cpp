#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }

    int mid = nums.size() / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    std::vector<int> leftNums(nums.begin(), nums.begin() + mid);
    std::vector<int> rightNums(nums.begin() + mid + 1, nums.end());

    root->left = sortedArrayToBST(leftNums);
    root->right = sortedArrayToBST(rightNums);

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    std::vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = sortedArrayToBST(nums);

    std::cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
