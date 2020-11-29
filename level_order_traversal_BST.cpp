#include <iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    
    int depth(TreeNode * root) {
        if (!root)
            return 0;
        return max(depth(root-> left), depth(root->right)) + 1;
    }
    
    vector <int> num_at_level (TreeNode* root, int level) {
        vector <int> level_val;
        if (! root)
            return {};
        if (level == 0)
            level_val.push_back(root -> val); 
        vector <int> left = num_at_level (root -> left, level - 1);
        vector <int> right = num_at_level (root -> right, level - 1);  
        for (int l: left)
            level_val.push_back(l);
        for (int r: right)
            level_val.push_back(r);
        return level_val;
    }
    
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> level_wise_values;
        int max_depth = depth(root);
        for (int i = 0; i < max_depth; i++)
            level_wise_values.push_back(num_at_level (root , i));
        return level_wise_values;
    } 
};