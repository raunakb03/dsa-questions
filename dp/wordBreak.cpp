// https : // leetcode.com/problems/word-break/description

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space - separated sequence of one or more dictionary words.Note that the same word in the dictionary may be reused multiple times in the segmentation.

#include <bits/stdc++.h>
using namespace std;

// memoization
bool f(string s, unordered_set<string> &st, int start, vector<int> &dp)
{
    if (start == s.size())
        return true;

    if (dp[start] != -1)
        return dp[start];
    for (int i = start; i < s.size(); i++)
    {
        if (st.count(s.substr(start, i + 1 - start)) && f(s, st, i + 1, dp))
        {
            return dp[start] = true;
        }
    }
    return dp[start] = false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<int> dp(s.size(), -1);
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    return f(s, st, 0, dp);
}

// tabulation
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, 0);
    dp[0] = true;
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && set.count(s.substr(j, i - j)))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}