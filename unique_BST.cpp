#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/unique-binary-search-trees-ii/

class Solution {
public:
    vector<TreeNode*> helper(int start, int end) {
        vector <TreeNode*> trees;
        if (start > end)
            return {NULL};
        for (int i = start; i <= end; i++) {
            vector <TreeNode*> left_branch = helper(start, i - 1);
            vector <TreeNode*> right_branch = helper(i + 1, end);
            
            for (TreeNode* l: left_branch)
                for(TreeNode* r: right_branch) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    trees.push_back(root);
                }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        vector <TreeNode*> trees = helper(1, n);
        return trees;
    }
};