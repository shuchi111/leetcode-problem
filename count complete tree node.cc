class Solution {
public:
    int height(TreeNode* root) {
        int h = 0;
        while(root) {
            root = root->left;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt = 1;
        while(root->left || root->right) {
            if(height(root->left) == height(root->right)) {
                root = root->right;
                cnt = cnt*2+1;
            } else {
                root = root->left;
                cnt = cnt*2;
            }
        }
       return cnt;
    }
};
