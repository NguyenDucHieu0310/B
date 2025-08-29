/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void PathSol(TreeNode*root,int targetSum, vector<vector<int>>&result, vector<int>&curSol ){
        if(root==NULL) return;
        curSol.push_back(root->val);
        if(root->val==targetSum&&!root->left&&!root->right){ result.push_back(curSol);}
        PathSol(root->left, targetSum-root->val,result,curSol) ;        
        PathSol(root->right, targetSum-root->val,result,curSol) ;
        curSol.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int>curSol;       
        PathSol(root,targetSum,result,curSol);
        return result;
    }
    
};