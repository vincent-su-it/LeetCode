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
    vector<TreeNode*> generateTrees(int n) {
         if(n == 0)
            return {nullptr};
        return build(1,n);
    }

    vector<TreeNode*> build(int start, int end){
        if(start > end){
            return {nullptr};
        }

        //存储每次递归生成的子树信息，返回到上一层的左子树或者右子树
        vector<TreeNode*> tmp_trees;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftTree = build(start, i-1);
            vector<TreeNode*> rightTree = build(i+1, end);

            for(auto& left : leftTree){
                for(auto& right : rightTree){
                    TreeNode* current_tree = new TreeNode(i);
                    current_tree->left = left;
                    current_tree->right = right;
                    tmp_trees.push_back(current_tree);
                }
            }
        }
        return tmp_trees;
    }
};