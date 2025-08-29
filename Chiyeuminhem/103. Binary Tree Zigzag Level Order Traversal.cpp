#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int n = 1;
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            
            if (n % 2) {
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            } else {
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    level.insert(level.begin(), node->val);
                    
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }
            
            result.push_back(level);
            n++;
        }
        
        return result;
    }
};

int main() {
    // Create a binary tree like the example
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create an instance of the Solution class
    Solution solution;
    
    // Call the zigzagLevelOrder function to get the zigzag level order traversal
    vector<vector<int> > result = solution.zigzagLevelOrder(root);
    
    // Print the result
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
    }
    cout << endl;
}
    
    return 0;
}

