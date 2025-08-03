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
    int findClosestLeaf(TreeNode* root, int k) {
        map<int, TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        while (true) {
            TreeNode* curr=q.front();
            q.pop();
            if (curr && curr->val==k) {
                if (!curr->left && !curr->right) {
                    return curr->val;
                }
                q=*(new queue<TreeNode*>());
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                if (m[curr->val]) {
                    q.push(m[curr->val]);
                }
                curr->val = -1;
                break;
            } else if (curr) {
                if (curr->left) {
                    q.push(curr->left);
                    m[curr->left->val]=curr;
                }
                if (curr->right) {
                    q.push(curr->right);
                    m[curr->right->val]=curr;
                }
            }
        }
        queue<TreeNode*> q2;
        while (q.size()>0) {
            TreeNode* curr = q.front();
            q.pop();
            if (!curr->left && !curr->right) {
                return curr->val;
            } else {
                if (curr->left && curr->left->val>0) {
                    q2.push(curr->left);
                }
                if (curr->right && curr->right->val>0) {
                    q2.push(curr->right);
                }
                if (m[curr->val] && m[curr->val]->val>0) {
                    q2.push(m[curr->val]);
                }
                curr->val=-1;
            }
            if (q.size()==0) {
                q=q2;
                q2=*(new queue<TreeNode*>());
            }
        }
        return 0;
    }
};