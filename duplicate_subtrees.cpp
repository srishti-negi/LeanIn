#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/find-duplicate-subtrees/

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
    unordered_map <string, int> subtrees;
    vector <TreeNode*> duplicate_subtrees;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return duplicate_subtrees;
    }
    string helper(TreeNode* root) {
        if (!root)
            return "";
        string tree_str = to_string(root->val) + "," + helper(root->left) + "," + helper(root->right);
        subtrees[tree_str]++;
        if (subtrees[tree_str] == 2)
            duplicate_subtrees.push_back(root);
        return tree_str;
    }
};