#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size() == 0)
            return nullptr;
        
        int n = postorder.size();
        int root_val = postorder[n - 1];
        int root_idx = find_idx(inorder, root_val);

        vector <int> left_in = generate_subtree(inorder, 0, root_idx - 1);
        vector <int> left_post = generate_subtree(postorder, 0, root_idx - 1);
        
        vector <int> right_in = generate_subtree(inorder, root_idx + 1, n - 1);
        vector <int> right_post = generate_subtree(postorder, root_idx, n - 2);
        
        TreeNode * root = new TreeNode(root_val);
        root -> left = buildTree(left_in, left_post);
        root -> right = buildTree(right_in, right_post);
        return root;
    }
};