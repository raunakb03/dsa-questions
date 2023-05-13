#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag;

    // check if giver char is in the link or not
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // insert the given char in the link
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // setting flag to true after the end of the word
    void setEnd()
    {
        flag = true;
    }

    // check if word is complete or not
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // moves to the reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        string word = prefix;
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return true;
    }
};