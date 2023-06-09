#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class node
    {
    public:
        int data;
        int row;
        int col;

        node(int d, int r, int c)
        {
            data = d;
            row = r;
            col = c;
        }
    };

    class compare
    {
    public:
        bool operator()(node *a, node *b)
        {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>> &nums)
    {

        int k = nums.size();

        priority_queue<node *, vector<node *>, compare> pq;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // step-1: create a minHeap for starting element of each list
        // and track maxi/mini
        for (int i = 0; i < k; i++)
        {
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            pq.push(new node(nums[i][0], i, 0));
        }

        int start = mini;
        int end = maxi;

        // process ranges
        while (!pq.empty())
        {
            node *temp = pq.top();
            pq.pop();

            mini = temp->data;

            // ranges or ans updation
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }

            // next element exists, n=nums[temp->row].size();
            if (temp->col + 1 < nums[temp->row].size())
            {
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                pq.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else
            {
                // next element doesn't exists
                break;
            }
        }

        return {start, end};
    }
};