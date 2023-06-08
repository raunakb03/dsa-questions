#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int s=0, l=0, sum=0;
        int length= 1e9;
        while(l<n){
            sum+=nums[l++];
            while(sum>=target){
                length= min(length, l-s);
                sum-=nums[s++];
            }
        }
        if(length==1e9) return 0;
        return length;
    }