#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    unordered_map <TreeNode*, int> depth;
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        if(depth.count(root))
            return depth[root];
        depth[root] = 1 + max(maxDepth(root -> left), maxDepth(root -> right));
        return depth[root];
    }
};