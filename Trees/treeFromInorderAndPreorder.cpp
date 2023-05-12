#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d)
    {
        this->val = d;
        left = NULL;
        right = NULL;
    }
};

int findPosition(vector<int>& inorder, int n, int ele){
        for(int i=0; i<n; i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& pre, vector<int>& in, int& ind, int n,  int start, int end){
        if(ind>=n || start>end) return NULL;

        int position= findPosition(in, n, pre[ind]);
        TreeNode* node= new TreeNode(pre[ind++]);

        node->left= solve(pre, in, ind, n, start, position-1);
        node->right= solve(pre, in, ind, n, position+1, end);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size= preorder.size();
        int val=0;
        TreeNode* ans= solve(preorder, inorder, val, size, 0, size-1);
        return ans;
    }