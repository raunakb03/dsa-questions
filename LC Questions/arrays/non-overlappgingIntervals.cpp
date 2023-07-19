class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        // if start of two are same then remove the one with the larger size
        for (int i = 1; i < intervals.size(); i++)
        {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            if (curr_start == start)
            {
                ans++;
            }
            // second completely inside the first
            else if (curr_start < end)
            {
                ans++;
                end = min(end, curr_end);
            }
            // overlapping
            else if (curr_end <= end)
            {
                ans++;
                if (curr_end < end)
                {
                    start = curr_start;
                    end = curr_end;
                }
            }
            else
            {
                start = curr_start;
                end = curr_end;
            }
        }
        return ans;
    }
};