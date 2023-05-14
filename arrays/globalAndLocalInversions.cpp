#include<bits/stdc++.h>
using namespace std;

 bool isIdealPermutation(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==i || nums[i]==i-1 || nums[i]==i+1) continue;
            return false;
        }
        return true;
    }