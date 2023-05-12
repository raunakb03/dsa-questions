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
int f(Node* root){
      if(root==NULL) return 0;
      
      int left= f(root->left);
      int right= f(root->right);
      int val= root->data;
      root->data= left+right;
      return val+left+right;
  }
    void toSumTree(Node *node)
    {
        int val= f(node);
    }