#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

pair<bool, int> f(Node* root){
        if(root==NULL) return {1, 0};
        if(root->left == NULL && root->right == NULL){
            return {1, root->data};
        }
        
        pair<bool, int> left= f(root->left);
        pair<bool, int> right= f(root->right);
        
        pair<int, int> ans;
        if(left.second+right.second==root->data){
            ans.first= 1 && left.first && right.first;
        }
        else ans.second= 0;
        ans.second= left.second+right.second+root->data;
        
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
         return f(root).first;
    }