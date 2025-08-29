#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> cur = {0};
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> findp = findPosition(root, cur, p);
        for(auto x:findp) cout<<x<<" ";
        cout<<endl;
        vector<int> findq = findPosition(root, cur, q);
        for(auto x:findq) cout<<x<<" ";
        cout<<endl;

        while (findp.size() != findq.size()) {
            if (findp.size() > findq.size()) findp.pop_back();
            else findq.pop_back();
        }
        for(auto x:findp) cout<<x<<" ";
        cout<<endl;
        for(auto x:findq) cout<<x<<" ";
        cout<<endl;

        int i = 1;
        TreeNode* t = root;
        while (i < findp.size() && findp[i] == findq[i]) {
            if (findp[i] == 0 && t->left) {
                t = t->left;
            } else if (findp[i] == 1 && t->right) {
                t = t->right;
            }
            i++;
        }
        return t;
    }

    
    vector<int> findPosition(TreeNode* root, vector<int>& cur, TreeNode* x) {
        if (!root) return {};

        if (root->val == x->val) {vector<int>found=cur; cur.clear();cur.push_back(0);return found;}

        cur.push_back(0);
        vector<int> l = findPosition(root->left, cur, x);
        if (!l.empty()) return l;
        cur.pop_back();

        cur.push_back(1);
        vector<int> r = findPosition(root->right, cur, x);
        if (!r.empty()) return r;
        cur.pop_back();

        return {};
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* result = sol.lowestCommonAncestor(root, root->left->right->right, root->left->left);
    cout << "Lowest Common Ancestor: " << result->val << endl;

    // Free the allocated memory
    delete root->left->left;
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
