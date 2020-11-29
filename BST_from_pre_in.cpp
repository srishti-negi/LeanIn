#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
vector <int> generate_subtree (vector <int> tree, int si, int ei) {
       
        vector <int> subtree;
        for(int i = si; i <= ei; i++)
            subtree.push_back(tree[i]);
        return subtree;
    }
    
    int find_idx (vector <int> arr, int val) {
        for (int i = 0; i < arr.size(); i++)
            if(arr[i] == val)
                return i;
        return -1;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(inorder.size() == 0)
            return nullptr;
        
        int n = inorder.size();
        int root_val = preorder[0];
        int root_idx = find_idx(inorder, root_val);

        vector <int> left_in = generate_subtree(inorder, 0, root_idx - 1);
        vector <int> left_pre = generate_subtree(preorder, 1, root_idx);
        
        vector <int> right_in = generate_subtree(inorder, root_idx + 1, n - 1);
        vector <int> right_pre = generate_subtree(preorder, root_idx + 1, n - 1);
        
        TreeNode * root = new TreeNode(root_val);
        root -> left = buildTree(left_pre, left_in);
        root -> right = buildTree(right_pre, right_in);
        return root;
    }
};