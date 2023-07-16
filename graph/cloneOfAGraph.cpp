class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    map<Node *, Node *> oldToNew;
    Node *dfs(Node *node)
    {
        if (oldToNew[node])
        {
            return oldToNew[node];
        }
        Node *copy = new Node(node->val);
        oldToNew[node] = copy;
        for (auto nod : node->neighbors)
        {
            copy->neighbors.push_back(dfs(nod));
        }
        return copy;
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        return dfs(node);
    }
};