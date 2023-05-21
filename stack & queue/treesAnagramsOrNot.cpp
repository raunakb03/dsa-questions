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
        this->left = NULL;
        this->right = NULL;
    }
};

bool areAnagrams(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
    unordered_map<int, int> m;
    while (!q1.empty() && !q2.empty())
    {
        int n1 = q1.size();
        int n2 = q2.size();

        if (n1 != n2)
            return false;

        while (n1--)
        {
            Node *node = q1.front();
            q1.pop();
            m[node->data]++;

            if (node->left)
                q1.push(node->left);
            if (node->right)
                q1.push(node->right);
        }

        while (n2--)
        {
            Node *node = q2.front();
            q2.pop();
            if (m.find(node->data) == m.end())
                return false;
            else
                m[node->data]--;

            if (m[node->data] == 0)
                m.erase(node->data);

            if (node->left)
                q2.push(node->left);
            if (node->right)
                q2.push(node->right);
        }
        if (m.size())
            return false;
    }
    if (q1.empty() && q2.empty())
        return true;
    return false;
}